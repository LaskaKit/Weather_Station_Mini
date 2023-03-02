/*
 * LaskaKit DIY Mini Weather Station - TMEP edition
 * Read Temperature, Humidity and pressure and send to TMEP.cz
 *
 * For settings see config.h
 *
 * E-mail: podpora@laskakit.cz
 * Web: laskakit.cz
 * Board: LaskaKit Meteo Mini - ESP32-C3 Dev Module
 * Sensor: LaskaKit BME280
 */

// EN: Fill in your sensor domain, preferably "Domain for sending values" to be more secure, without http://
// CZ: Vypln tvou domenu u cidla, ktere sis zalozil na tmep.cz,
// zvol domenu pro zasilani hodnot pro lepsi zabezpeceni, uved ji bez http://
String serverName = "DOMENA.tmep.cz";

// Libraries
#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>      // BME280 by Adafruit
#include <ESP32AnalogRead.h>      // ESP32AnalogRead by madhephaestus https://github.com/madhephaestus/ESP32AnalogRead
#include <WiFiManager.h>          // WiFi manager by tzapu https://github.com/tzapu/WiFiManager

#define BME280_ADDRESS (0x77)     // 0x77 - cut left and solder right pad on board, otherwise it will be 0x76
#define SLEEP_SEC 5*60            // Measurement interval (seconds) - 5 minutes - you can adjust to higher interval
                                  // if battery is getting drained quicker than you can charge it
#define ADC_PIN 0                 // ADC pin on LaskaKit Meteo mini
#define deviderRatio 1.7693877551 // Voltage devider ratio on ADC pin 1M + 1.3MOhm

// Instance creation
Adafruit_BME280 bme;
ESP32AnalogRead adc;

float temperature;
float pressure;
float humidity;
float bat_voltage;

void postData(){

  if(WiFi.status()== WL_CONNECTED) {
    HTTPClient http;

    // Variables with measurements are send to server of your choice - temperature, humidity, pressure, battery voltage and Wi-Fi signal strength
    String serverPath = "http://" + serverName + "/index.php?temp=" + temperature + "&humV=" + humidity + "&pressV=" + pressure + "&v=" + bat_voltage + "&rssi=" + WiFi.RSSI();

    // begin of HTTP connection
    http.begin(serverPath.c_str());

    // http get request
    int httpResponseCode = http.GET();

    if (httpResponseCode>0) {
      Serial.print("HTTP response: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  } else
      Serial.println("Wi-Fi disconnected");
}

void GoToSleep(){
    delay(1);
  // ESP Deep Sleep
  Serial.println("ESP in sleep mode");
  esp_sleep_enable_timer_wakeup(SLEEP_SEC * 1000000);
  esp_deep_sleep_start();
}

// pripojeni k WiFi | WiFi Connection
void WiFiConnection(){
  // Probudit WiFi | Wake up WiFi Modem
  WiFi.mode(WIFI_STA);

    // WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wm;

    // reset settings - wipe stored credentials for testing
    // these are stored by the esp library
    //wm.resetSettings();

    // Automatically connect using saved credentials,
    wm.setConfigPortalTimeout(180);   // set portal time to 3 min, then sleep.
    bool res;
    res = wm.autoConnect("LaskaKitMeteo", "meteostation"); // password protected ap

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

  Serial.print("Temperature: "); Serial.print(temperature); Serial.println("°C");
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

  // initilizace BME280 | BME280 Initialization
  Wire.begin(19,18); // SDA SCL
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