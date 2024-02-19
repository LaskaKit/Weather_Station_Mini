/* LaskaKit DIY Mini Weather Station.  https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/#productDiscussion
 * TMEP edition
 * Read Temperature, Humidity and pressure and send to TMEP.cz
 * 
 * For settings see config.h
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 * Board: ESP32-C3 Dev Module
 * 
 */

// připojení knihoven
#include "config.h"            // change to config.h and fill the file.

#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>      // BME280 by Adafruit 
#include <ESP32AnalogRead.h>      // ESP32AnalogRead by madhephaestus https://github.com/madhephaestus/ESP32AnalogRead 
#include <WiFiManager.h>          // WiFi manager by tzapu https://github.com/tzapu/WiFiManager

#define BME280_ADDRESS (0x77)     // Default on LaskaKit module
#define SLEEP_SEC 15*60           // Measurement interval (seconds)
#define ADC_PIN 0                 // ADC pin on LaskaKit Meteo mini
#define deviderRatio 1.7693877551 // Voltage devider ratio on ADC pin 1M + 1.3MOhm
#define SDA 19
#define SCL 18
#define PIN_ON 3

// Vytvoření instance | Instance creation
Adafruit_BME280 bme;
ESP32AnalogRead adc;

float temperature;
float pressure;
float humidity;
float bat_voltage;

void postData(){

  if(WiFi.status()== WL_CONNECTED) {
    HTTPClient http;
      
    //GUID, nasleduje hodnota teploty, pro vlhkost "humV", pro CO2 "CO2", pro napeti baterie "v"
    String serverPath = serverName + "" + GUID + "=" + temperature + "&humV=" + humidity + "&pressV=" + pressure + "&v=" + bat_voltage; 
      
    // zacatek http spojeni
    http.begin(serverPath.c_str());
      
    // http get request
    int httpResponseCode = http.GET();
      
    if (httpResponseCode>0) {
      Serial.print("HTTP odpoved: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error kod: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  } else 
      Serial.println("Wi-Fi odpojeno");

}

void GoToSleep(){
    delay(1);
  // ESP Deep Sleep 
  digitalWrite(PIN_ON, LOW);   // Turn off the uSUP power
  Serial.println("ESP in sleep mode");
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}

// pripojeni k WiFi | WiFi Connection
void WiFiConnection(){
    // Probudit WiFi | Wake up WiFi Modem
  WiFi.mode( WIFI_STA);

 //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    //wm.resetSettings();

    // Automatically connect using saved credentials,
    // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
    // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
    // then goes into a blocking loop awaiting configuration and will return success result
    
    wm.setConfigPortalTimeout(180);   // set portal time to  3 min, then sleep.
    bool res;
    res = wm.autoConnect("LaskaKit AutoConnectAP","laskakit"); // password protected ap

    if(!res) {
        Serial.println("Failed to connect");
        // ESP.restart();
    } 
    else {
        //if you get here you have connected to the WiFi    
        Serial.println("Wi-Fi connected successfully");
    }
}

// Přečíst data z BME280 | Read data from BME280
void readBME(){
  temperature = bme.readTemperature();
  humidity    = bme.readHumidity();
  pressure    = bme.readPressure() / 100.0F;  
  
  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% RH");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println("hPa");
}


// Měření napětí baterie | Battery voltage measurement
void readBat(){
  bat_voltage = adc.readVoltage()*deviderRatio;
  Serial.print("Battery voltage " + String(bat_voltage) + "V");

}

void setup() {
  // Hned vypneme WiFi | disable WiFi, coming from DeepSleep, as we do not need it right away
  WiFi.mode( WIFI_OFF );
  delay( 1 );
  
  adc.attach(ADC_PIN);  

  Serial.begin(115200);
  while(!Serial) {} // Wait

  // for board version over 3.5 need to turn uSUP ON
  pinMode(PIN_ON, OUTPUT);      // Set EN pin for uSUP stabilisator as output
  digitalWrite(PIN_ON, HIGH);   // Turn on the uSUP power

  // initilizace BME280 | BME280 Initialization
  Wire.begin(SDA,SCL);
  if (! bme.begin(BME280_ADDRESS)) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.println("-- Weather Station Scenario --");
  Serial.println("forced mode, 1x temperature / 1x humidity / 1x pressure oversampling,");
  Serial.println("filter off");
  bme.setSampling(Adafruit_BME280::MODE_FORCED,
                  Adafruit_BME280::SAMPLING_X1, // temperature
                  Adafruit_BME280::SAMPLING_X1, // pressure
                  Adafruit_BME280::SAMPLING_X1, // humidity
                  Adafruit_BME280::FILTER_OFF   );
  delay(10);

  readBME();
  readBat();     
  
  // Pripojeni k WiFi | Connect to WiFi
  WiFiConnection();
  postData();

  WiFi.disconnect(true);
  GoToSleep();
}

void loop(){
  // Nepotřebujeme loop | We dont use the loop
}