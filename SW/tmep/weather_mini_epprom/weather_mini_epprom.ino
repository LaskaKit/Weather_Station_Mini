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

#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <EEPROM.h>
#include <Adafruit_Sensor.h>              // Sensor by Adafruit 
#include <Adafruit_BME280.h>              // BME280 by Adafruit 
#include <WiFiManager.h>                  // WiFi manager by tzapu https://github.com/tzapu/WiFiManager

#define BME280_ADDRESS      (0x77)        // Default on LaskaKit module
#define ADC_PIN             0             // ADC pin on LaskaKit Meteo mini
#define deviderRatio        1.7693877551  // Voltage devider ratio on ADC pin 1M + 1.3MOhm
#define configPortalTimeout 180
#define SDA                 19
#define SCL                 18
#define POWER               3

//flag for saving data
bool shouldSaveConfig = false;

// Vytvoření instance | Instance creation
Adafruit_BME280 bme;

float temperature;
float pressure;
float humidity;
float bat_voltage;
int rssi;

//callback notifying us of the need to save config
void saveConfigCallback () {
  Serial.println("Should save config");
  shouldSaveConfig = true;
}

/********************** EEPROM Section *****************/
typedef struct {
  char domain_name[40]  = "";
  char sleep_min_value[3]  = "";
}

WMSettings;
WMSettings domain;
WMSettings sleep_min;

void eeprom_read() {
  EEPROM.begin(512);
  EEPROM.get(0, domain);
  EEPROM.get(100, sleep_min);
  Serial.println("EEPROM readed. Domain: \"" + String(domain.domain_name) + "\", wake up every " + sleep_min.sleep_min_value + " minutes");

  EEPROM.end();
}

void eeprom_saveconfig() {
  EEPROM.begin(512);
  EEPROM.put(0, domain);
  EEPROM.put(100, sleep_min);
  EEPROM.commit();
  Serial.println("EEPROM saved: Domain: " + String(domain.domain_name) + ". Wake up every " + sleep_min.sleep_min_value + " minutes");

  EEPROM.end();
}
/********************************************************/

void postData(){
  if(WiFi.status()== WL_CONNECTED) {
    HTTPClient http;
      
    //GUID, nasleduje hodnota teploty, pro vlhkost "humV", pro CO2 "CO2", pro napeti baterie "v"
    String serverPath = "http://" + String(domain.domain_name) + ".tmep.cz/index.php?&tempV=" + temperature + "&humV=" + humidity + "&pressV=" + pressure + "&v=" + bat_voltage + "&rssi=" + rssi; 
    Serial.println(serverPath);

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
  } else Serial.println("Wi-Fi odpojeno");
}

void GoToSleep(){
  delay(1);
  // ESP Deep Sleep 
  digitalWrite(POWER, LOW);   // Turn off the uSUP power
  int sleep_time_min = atoi(sleep_min.sleep_min_value);
  Serial.println("Going to sleep for " + String(sleep_time_min) + " minutes");
  esp_sleep_enable_timer_wakeup(sleep_time_min * 60 * 1000000);
  esp_deep_sleep_start();
}

// pripojeni k WiFi | WiFi Connection
void WiFiConnection(){
  // Probudit WiFi | Wake up WiFi Modem
  WiFi.mode( WIFI_STA);
  eeprom_read();

  WiFiManagerParameter custom_domain_name("domain_name", "Domain", domain.domain_name, 40);           //(id, label, defaultValue, length)
  WiFiManagerParameter custom_sleep_min_value("sleep_min_value", "Wake up every minutes",  sleep_min.sleep_min_value, 3);    //(id, label, defaultValue, length)

  //WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wm;
  wm.setSaveParamsCallback( saveConfigCallback );
  wm.addParameter(&custom_domain_name);
  wm.addParameter(&custom_sleep_min_value);

  // reset settings - wipe stored credentials for testing
  // these are stored by the esp library
  //wm.resetSettings();

  // Automatically connect using saved credentials,
  // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
  // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
  // then goes into a blocking loop awaiting configuration and will return success result
    
  wm.setConfigPortalTimeout(180);   // set portal time to  3 min, then sleep.
  bool res = wm.autoConnect("LaskaKitMeteo","meteomini"); // password protected ap

  if(!res) {
    Serial.println("Failed to connect");
  } else {
    //if you get here you have connected to the WiFi    
    Serial.println("Wi-Fi connected successfully");
  }
  strcpy(domain.domain_name, custom_domain_name.getValue());
  strcpy(sleep_min.sleep_min_value, custom_sleep_min_value.getValue());

  if(shouldSaveConfig){
    eeprom_saveconfig();
  } else Serial.println("Data not saved to EEPROM");

  rssi = WiFi.RSSI();
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
  bat_voltage = analogReadMilliVolts(ADC_PIN) * deviderRatio / 1000;
  Serial.println("Battery voltage " + String(bat_voltage) + "V");

}

void setup() {
  // Hned vypneme WiFi | disable WiFi, coming from DeepSleep, as we do not need it right away
  WiFi.mode( WIFI_OFF );
  delay( 1 );

  Serial.begin(115200);
  while(!Serial) {} // Wait for serrial ready

  // for board version > 3.5 need to turn uSUP ON
  pinMode(POWER, OUTPUT);      // Set EN pin for uSUP stabilisator as output
  digitalWrite(POWER, HIGH);   // Turn on the uSUP power

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

void loop() {
  // Nepotřebujeme loop | We dont use the loop
}