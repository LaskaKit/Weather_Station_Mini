/* LaskaKit DIY Weather Station.  
 *  This is BETA version of versatile code used for TMEP.CZ(.EU) together with Meteo Mini ESP32-C3 and sensors.
 *  Description: After the uploading, WiFi manager will create an AP: LaskaKit Meteo Config
 *  Connect to this AP through smart phone or laptop. Also, you have to: 
 *  - fill Subdomain,
 *  - choose Domain: TMEP.CZ or EU,
 *  - fill How long you want the weather station to sleep in minutes,
 *  - choose sensor, now are available: 
 *    + SHT40: (0x44) or (0x45), 
 *    + BME280: (0x77) or (0x76),
 *    + SCD41, 
 *    + DS18B20, 
 *    + SHT4x+BMP280:
 *      - SHT4x: (0x44) or (0x45), 
 *      - BMP280: (0x77) or (0x76).
 * 
 * Buy your DIY kit here:             https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/
 * main HW in the kit:
 *  - Board:   LaskaKit Meteo Mini    https://www.laskakit.cz/laskakit-meteo-mini/
 *  - Sensor:  SHT40                  https://www.laskakit.cz/laskakit-sht40-senzor-teploty-a-vlhkosti-vzduchu/
 *  - Sensor:  SHT45                  https://www.laskakit.cz/laskakit-sht45-senzor-teploty-a-vlhkosti-vzduchu/
 *  - Sensor:  BME280                 https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/            Tested
 *  - Sensor:  SCD41                  https://www.laskakit.cz/laskakit-scd41-senzor-co2--teploty-a-vlhkosti-vzduchu/
 *  - Sensor:  DS18B20                https://www.laskakit.cz/dallas-ds18b20-orig--digitalni-vodotesne-cidlo-teploty-1m/  Tested
 *  - Sensor:  SHT4x+BMP280           https://www.laskakit.cz/laskakit-outdoor-meteo-thp-senzor-sht40-bmp280
 *  - Battery LiPol 603048 900mAh     https://www.laskakit.cz/ehao-lipol-baterie-603048-900mah-3-7v/
 * 
 * Changes in libraries:
 * 1. Logo in wm_strings_en.h: 
 *    const char HTTP_ROOT_MAIN[]        PROGMEM = "<div style='text-align: center;'><h3>WiFiManager</h3><img title=' alt=' src='data:image/jpeg;base64,iVBORw0KGgoAAAANSUhEUgAAAOgAAAA8CAYAAABsBvZBAAAACXBIWXMAACxLAAAsSwGlPZapAAAE9GlUWHRYTUw6Y29tLmFkb2JlLnhtcAAAAAAAPD94cGFja2V0IGJlZ2luPSLvu78iIGlkPSJXNU0wTXBDZWhpSHpyZVN6TlRjemtjOWQiPz4gPHg6eG1wbWV0YSB4bWxuczp4PSJhZG9iZTpuczptZXRhLyIgeDp4bXB0az0iQWRvYmUgWE1QIENvcmUgNy4xLWMwMDAgNzkuZWRhMmIzZmFjLCAyMDIxLzExLzE3LTE3OjIzOjE5ICAgICAgICAiPiA8cmRmOlJERiB4bWxuczpyZGY9Imh0dHA6Ly93d3cudzMub3JnLzE5OTkvMDIvMjItcmRmLXN5bnRheC1ucyMiPiA8cmRmOkRlc2NyaXB0aW9uIHJkZjphYm91dD0iIiB4bWxuczp4bXA9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC8iIHhtbG5zOmRjPSJodHRwOi8vcHVybC5vcmcvZGMvZWxlbWVudHMvMS4xLyIgeG1sbnM6cGhvdG9zaG9wPSJodHRwOi8vbnMuYWRvYmUuY29tL3Bob3Rvc2hvcC8xLjAvIiB4bWxuczp4bXBNTT0iaHR0cDovL25zLmFkb2JlLmNvbS94YXAvMS4wL21tLyIgeG1sbnM6c3RFdnQ9Imh0dHA6Ly9ucy5hZG9iZS5jb20veGFwLzEuMC9zVHlwZS9SZXNvdXJjZUV2ZW50IyIgeG1wOkNyZWF0b3JUb29sPSJBZG9iZSBQaG90b3Nob3AgMjMuMSAoTWFjaW50b3NoKSIgeG1wOkNyZWF0ZURhdGU9IjIwMjEtMDctMTJUMTg6NDk6MTcrMDI6MDAiIHhtcDpNb2RpZnlEYXRlPSIyMDIxLTEyLTIwVDE0OjA5OjUwKzAxOjAwIiB4bXA6TWV0YWRhdGFEYXRlPSIyMDIxLTEyLTIwVDE0OjA5OjUwKzAxOjAwIiBkYzpmb3JtYXQ9ImltYWdlL3BuZyIgcGhvdG9zaG9wOkNvbG9yTW9kZT0iMyIgeG1wTU06SW5zdGFuY2VJRD0ieG1wLmlpZDpkNGQwNDYxZS03MjkwLTQwNTctOGRmNy1iZjEzYTAyZTI1MTkiIHhtcE1NOkRvY3VtZW50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' /><h2>{v}</h2></div>";
 * 
 * Email:podpora@laskakit.cz
 * Web:laskakit.cz
 * Written by laskakit.cz (2025)
 * 
 * Changelog:
 *    v2.3 - 
 *        * Added sleep reason, 
 *        * Added message with version
 *    v2.2 - Added restart reason
 * 
 */

#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <EEPROM.h>
#include <Adafruit_Sensor.h>              // Unified Sensor by Adafruit 1.1.15
#include <Adafruit_BME280.h>              // BME280 by Adafruit https://github.com/adafruit/Adafruit_BME280_Library (tested 2.2.4)
#include <Adafruit_BMP280.h>              // BMP280 by Adafruit 2.6.8
#include <Adafruit_SHT4x.h>               // SHT4x by Adafruit 1.0.3
#include <SensirionI2CScd4x.h>            // SCD4x by Sensirion https://github.com/Sensirion/arduino-i2c-scd4x (tested v0.4.0)
#include <OneWire.h>                      // OneWire by Paul Stoffregen
#include <DallasTemperature.h>            // DallasTemperature by Miles Burton https://github.com/milesburton/Arduino-Temperature-Control-Library (tested 4.0.1)
#include <WiFiManager.h>                  // WiFiManager by tzapu https://github.com/tzapu/WiFiManager (tested 2.0.17)
#include <math.h>                         // pro isfinite()

/////////////////////////////////
// Uncomment for correct board
/////////////////////////////////

//#define MeteoMini_V3                      // Tested on LaskaKit Meteo mini V3.2, V3.5
#define MeteoMini_V4                  // Tested on LaskaKit Meteo mini V4.0   


#define version               2.3           // Firmware version
#define configPortalTimeout   180           // Config portal timeout in seconds

#define ADC_PIN             0             // ADC pin on LaskaKit Meteo mini
#define deviderRatio        1.7693877551  // Voltage devider ratio on ADC pin 1M + 1.3MOhm
#define SDA                 19            // I2C SDA pin on LaskaKit Meteo mini
#define SCL                 18            // I2C SCL pin on LaskaKit Meteo mini
#define ONE_WIRE_BUS        10            // DS18B20 pin on LaskaKit Meteo mini

#ifdef MeteoMini_V3
  #define PWR_PIN             3             // Power pin for sensors
  #define board               "LaskaKit_Meteo_mini_V3" // Board name"

#elif defined MeteoMini_V4
  #define PWR_PIN             4             // Power pin for sensors
  #define OnDemandPin         5             // On demand button for calling the configuration portal. Push when the device is powered on to enter the configuration portal.
  #define board               "LaskaKit_Meteo_mini_V4" // Board name"

#else
  #error "Board not defined!"
#endif


// Vytvoření instance | Instance creation
WiFiManager       wm;
Adafruit_BME280   bme;
Adafruit_BMP280   bmp;
Adafruit_SHT4x    sht4x = Adafruit_SHT4x();
SensirionI2CScd4x scd4x;

float     temperature;
float     pressure;
float     humidity;
uint16_t  co2;
float     bat_voltage;
int       rssi;
int EEPROMaddress = 0;

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature DS18B20(&oneWire);
// Variable to store the address of the DS18B20 sensor
DeviceAddress sensorAddress;


// Custom parameters
char serverAddress[40]  = "";
int domain              = 0;                        // Default domain (0: tmep.cz, 1: tmep.eu)
int sleepTime           = 15;                       // Default sleep time in minutes
int sensorType          = 1;                        // Default sensor type (0: SHT40, 1: BME280, 2: SCD41, 3: DS18B20 4:SHT4x+BMP280)
const char *bufferDomain = R"(
<!-- INPUT SELECT -->
<br/>
<label for='domainType'>Choose your domain:</label>
<select name="domainType" id="domainType" class="button">
<option value="0" selected>tmep.cz</option>
<option value="1">tmep.eu</option>
</select>
)";
const char *bufferSensor = R"(
<!-- INPUT SELECT -->
<br/>
<label for='sensorType'>Choose your sensor:</label>
<select name="sensorType" id="sensorType" class="button">
<option value="0" selected>SHT40</option>
<option value="1">BME280</option>
<option value="2">SCD41</option>
<option value="3">DS18B20</option>
<option value="4">SHT4x+BMP280</option>
</select>
)";
WiFiManagerParameter custom_serverAddress("server", "Your subdomain: (max 40 chars)", serverAddress, 40);   //(id, label, defaultValue, length)
WiFiManagerParameter custom_domain(bufferDomain);
WiFiManagerParameter custom_sleepTime("sleepTime", "Sleep Time: (max 200 minutes)", String(sleepTime).c_str(), 6);  //(id, label, defaultValue, length)
WiFiManagerParameter custom_sensorType(bufferSensor);

void eeprom_read() {
  // Start the EEPROM
  if (!EEPROM.begin(512)) {
    Serial.println("Failed to initialize EEPROM");
    return; // Return early if EEPROM initialization fails
  }

  EEPROMaddress = 0;

  EEPROM.readString(EEPROMaddress).toCharArray(serverAddress, sizeof(serverAddress));
  EEPROMaddress += sizeof(serverAddress);

  domain = EEPROM.readInt(EEPROMaddress);
  EEPROMaddress += sizeof(int);

  sleepTime = EEPROM.readInt(EEPROMaddress);
  EEPROMaddress += sizeof(int);

  sensorType = EEPROM.readInt(EEPROMaddress);

  Serial.println("EEPROM readed. Subdomain: " + String(serverAddress) + "; Domain " + String(domain) + "; Wake up every " + String(sleepTime) + " minutes" + "; Sensor type: " + String(sensorType) + ".");
  EEPROM.end();
}

void eeprom_saveconfig() {
    
  Serial.println("Saving config...");
  // Start the EEPROM
  if (!EEPROM.begin(512)) {
    Serial.println("Failed to initialize EEPROM");
    return; // Return early if EEPROM initialization fails
  }

  EEPROMaddress = 0;
  strncpy(serverAddress, custom_serverAddress.getValue(), sizeof(serverAddress) - 1);
  char* endptr;

  if (wm.server->hasArg("domainType")) {
    domain = wm.server->arg("domainType").toInt();
  } else {
    Serial.println("Error: domainType argument not found");
    domain = 0; // Default value
  }

  sleepTime = strtol(custom_sleepTime.getValue(), &endptr, 10);
  if (*endptr != '\0') {
    Serial.println("Invalid input for sleepTime");
    sleepTime = 15; // Default value
  }

  if (wm.server->hasArg("sensorType")) {
    sensorType = wm.server->arg("sensorType").toInt();
  } else {
    Serial.println("Error: sensorType argument not found");
    sensorType = -1; // Default value, so it will be wrong and configuration portal will be started again
  }
 
  // Save the custom parameters to EEPROM
  if (!EEPROM.writeString(EEPROMaddress, serverAddress)) {
    Serial.println("Failed to write serverAddress to EEPROM");
  }
  EEPROMaddress += sizeof(serverAddress);

  if(!EEPROM.writeInt(EEPROMaddress, domain)) {
    Serial.println("Failed to write domain to EEPROM");
  }
  EEPROMaddress += sizeof(int);
  if (!EEPROM.writeInt(EEPROMaddress, sleepTime)) {
    Serial.println("Failed to write sleepTime to EEPROM");
  }
  EEPROMaddress += sizeof(int);
 
  if (!EEPROM.writeInt(EEPROMaddress, sensorType)) {
    Serial.println("Failed to write sensorType to EEPROM");
  }

  boolean ok = EEPROM.commit();
  Serial.print((ok) ? "EEPROM Commit OK" : "EEPROM Commit failed");
  Serial.println(": Subdomain: " + String(serverAddress) + "; Domain " + String(domain) + "; Wake up every " + String(sleepTime) + " minutes" + "; Sensor type: " + String(sensorType) + ".");
  EEPROM.end();
}

// Kontrola, zda hodnota je číslo (není NaN/Inf) a v rozsahu | Check if the value is a number (not NaN/Inf) and if it is in range
bool okTemperature(float t) {
  return isfinite(t) && t > -40 && t < 60;
}

bool okHumidity(float h) {
  return isfinite(h) && h >= 0 && h <= 100;
}

bool okPressure(float p) {
  return isfinite(p) && p > 850 && p < 1100;
}

bool okCO2(uint16_t c) {
  return c >= 250 && c <= 5000; // CO₂ v ppm
}

// Restart ESP
void restartNow(const char* reason) {
  Serial.print("Restart due to: ");
  Serial.println(reason ? reason : "unknown");
  Serial.flush();

  // vypnout periferie, ať je to čisté
  WiFi.disconnect(true, true);
  delay(50);
  digitalWrite(PWR_PIN, LOW);   // vypnout napájení pro senzory

  esp_restart();
}

void ConfigPortalOnDemand() {
  Serial.println("Starting configuration portal");
  custom_serverAddress.setValue(serverAddress,40);
  custom_sleepTime.setValue(String(sleepTime).c_str(),6);
  wm.startConfigPortal("LaskaKit Meteo Config");            // If settings was not correct, start configuration portal
  restartNow("Configuration portal is closed");                                           // Restart the device after configuration portal is closed    
}


void postData() {
  if(WiFi.status()== WL_CONNECTED) {
    HTTPClient http;

    String serverPath = "http://"; 

    switch (domain) {
      case 0:               // tmep.cz
        Serial.println("Generating serverPath case: 0 - tmep.cz");
        serverPath += String(serverAddress) + ".tmep.cz/?temp=" + temperature;
        break;
      case 1:               // tmep.eu
        Serial.println("Generating serverPath case: 1 - tmep.eu");
        serverPath += String(serverAddress) + ".tmep.eu/?temp=" + temperature;
        break;
      default:              // If setted wrong
        Serial.print("Error, domain value is " + String(domain) + ", should be from 0 to 1! ");
        ConfigPortalOnDemand();
        break;
    }

    switch (sensorType) {
      case 0:               // SHT4x
        Serial.println("Generating serverPath case: 0 - SHT4x");
        serverPath += "&humV=" + String(humidity) + "&voltage=" + String(bat_voltage) + "&rssi=" + String(rssi);
        break;
      case 1:               // BME280
        Serial.println("Generating serverPath case: 1 - BME280");
        serverPath += "&humV=" + String(humidity) + "&pressV=" + String(pressure) + "&voltage=" + String(bat_voltage) + "&rssi=" + String(rssi);
        break;
      case 2:               // SCD4x
        Serial.println("Generating serverPath case: 2 - SCD4x");
        serverPath += "&humV=" + String(humidity) + "&CO2=" + String(co2) + "&voltage=" + String(bat_voltage) + "&rssi=" + String(rssi);
        break;
      case 3:               // DS18B20
        Serial.println("Generating serverPath case: 3 - DS18B20");
        serverPath += "&voltage=" + String(bat_voltage) + "&rssi=" + String(rssi);
        break;
      case 4:               // DS18B20
        Serial.println("Generating serverPath case: 4 - SHT4x+BMP280");
        serverPath += "&humV=" + String(humidity) + "&pressV=" + String(pressure) + "&voltage=" + String(bat_voltage) + "&rssi=" + String(rssi);
        break;
      default:              // If setted wrong
        Serial.print("Error, sensor value is " + String(sensorType) + ", should be from 0 to 4! ");
        ConfigPortalOnDemand();
        break;
    }

    Serial.println("Generating serverPath: adding message");
        serverPath += "&msg=" "Board:%20" + String(board) + ";%20SW%20ver:%20" + String(version);

    Serial.println(serverPath);

    // zacatek http spojeni
    http.begin(serverPath.c_str());
      
    // http get request
    int httpResponseCode = http.GET();
      
    if (httpResponseCode == 200) {
      Serial.print("HTTP response : ");
      Serial.println(httpResponseCode);
      Serial.println("Data posted successfully");
    } else if (httpResponseCode == 404) {
      Serial.print("HTTP response: ");
      Serial.println(httpResponseCode);
      Serial.println("Error: There is no sensor on this domain, wrong domain?");
      ConfigPortalOnDemand();
    } else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  } else 
    Serial.println("Wi-Fi disconnected");
}

// ESP Deep Sleep 
void GoToSleep(const char* reason) {
  Serial.print("Going to sleep for " + String(sleepTime) + " minutes due to: ");
  Serial.println(reason ? reason : "unknown");
  Serial.flush();
  delay(100);
    // vypnout periferie, ať je to čisté
  WiFi.disconnect(true, true);
  delay(100);
  digitalWrite(PWR_PIN, LOW);  // Turn off the uSUP power | Vypnout napájení pro senzory

  esp_sleep_enable_timer_wakeup(sleepTime * 60 * 1000000);
  esp_deep_sleep_start();
}
void WiFiConnection_new() {
  WiFi.persistent(false);            // [FIX] nepiš do NVS při pokusech
  WiFi.mode(WIFI_STA);               // STA mód
  delay(120);                        // [FIX] nech driver naběhnout

  //wm.resetSettings();              // testovací mazání – ponech zakomentované

  // Set save config callback
  wm.setSaveConfigCallback(eeprom_saveconfig);

  // Předvyplnění parametrů
  custom_serverAddress.setValue(serverAddress, 40);
  custom_sleepTime.setValue(String(sleepTime).c_str(), 6);

  // Custom parametry
  wm.addParameter(&custom_serverAddress);
  wm.addParameter(&custom_domain);
  wm.addParameter(&custom_sleepTime);
  wm.addParameter(&custom_sensorType);

  // WiFiManager nastavení
  wm.setDarkMode(true);
  wm.setConfigPortalTimeout(5 * 60); // 5 min portál
  wm.setBreakAfterConfig(true);      // po uložení/timeoutu se vrať
  wm.setWiFiAutoReconnect(true);     // [FIX] automatický reconnect
  wm.setCleanConnect(true);          // [FIX] čisté připojení bez zbytků stavů

  if (!wm.autoConnect("LaskaKit Meteo Config")) {
    Serial.println("Failed to connect");
  } else {
    Serial.println("Wi-Fi connected successfully");
    rssi = WiFi.RSSI();
  }
}

// pripojeni k WiFi | WiFi Connection
void WiFiConnection() {

  // Probudit WiFi | Wake up WiFi Modem
  WiFi.mode( WIFI_STA);

  // reset settings - wipe stored credentials for testing
  //wm.resetSettings();

  // Set save config callback
  wm.setSaveConfigCallback(eeprom_saveconfig);

  custom_serverAddress.setValue(serverAddress,40);
  custom_sleepTime.setValue(String(sleepTime).c_str(),6);

  // Set custom parameters
  wm.addParameter(&custom_serverAddress);
  wm.addParameter(&custom_domain);
  wm.addParameter(&custom_sleepTime);
  wm.addParameter(&custom_sensorType);

  wm.setDarkMode(true);
  wm.setConfigPortalTimeout(5*60);   // set portal time to  5 min, then sleep.
  wm.setBreakAfterConfig(true);      // exit after config, even if connection is unsuccessful.

  if(!wm.autoConnect("LaskaKit Meteo Config")) {
    Serial.println("Failed to connect");
  } else {
    //if you get here you have connected to the WiFi    
    Serial.println("Wi-Fi connected successfully");
    rssi = WiFi.RSSI();
  }

}

// Přečíst data z SHT4x | Read data from SHT4x
void readSHT4x() {

  Wire.begin(SDA,SCL);
  delay(200);                                  // Wait for bus to boot in (we have inconsistent results couple times per day without this)

  if (!sht4x.begin()) {
    Serial.println("Error: Can't find a SHT4x sensor. Or wrong sensor type!");
    ConfigPortalOnDemand();
  } 
  Serial.println("SHT4x FOUND");
  sht4x.setPrecision(SHT4X_LOW_PRECISION);
  sht4x.setHeater(SHT4X_NO_HEATER);

  sensors_event_t hum, temp;
  sht4x.getEvent(&hum, &temp);

  if (!okTemperature(temp.temperature) || !okHumidity(hum.relative_humidity)) {
    Serial.println("SHT4x invalid -> restart");
    restartNow("SHT4x data invalid");
  }

  temperature = temp.temperature;
  humidity = hum.relative_humidity;

  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% RH");
}

// Přečíst data z BME280 | Read data from BME280
void readBME() {

  Wire.begin(SDA,SCL);
  delay(200);                                  // Wait for bus to boot in (we have inconsistent results couple times per day without this)

  if (! bme.begin(0x77)) {                      // try default address on LaskaKit module    
    Serial.println("Can't find a BME280 sensor on 0x77 address. Trying 0x76 ..."); 
      if (! bme.begin(0x76)) {                  // try another address BME280
        Serial.println("Error: Can't find a BME280 sensor. Or wrong sensor type!");
        ConfigPortalOnDemand();
      }
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
  bme.takeForcedMeasurement();                 // DŮLEŽITÉ

  if (!okTemperature(bme.readTemperature()) || !okHumidity(bme.readHumidity()) || !okPressure(bme.readPressure() / 100.0F)) {
    Serial.println("BME280 invalid -> restart");
    restartNow("BME280 data invalid");
  }

  temperature = bme.readTemperature();
  humidity    = bme.readHumidity();
  pressure    = bme.readPressure() / 100.0F;  
  
  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% RH");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println("hPa");
}

// Přečíst data z SCD41 | Read data from SCD41
void readSCD4x() {

  Wire.begin(SDA,SCL);
  delay(200);                                  // Wait for bus to boot in (we have inconsistent results couple times per day without this)
  scd4x.begin(Wire);

  if (scd4x.startPeriodicMeasurement()) {
    Serial.println("Error: Can't find a SCD41 sensor. Or wrong sensor type!");
    ConfigPortalOnDemand();
  }
  Serial.println("SCD41 found");
  delay(3000);

  if (scd4x.readMeasurement(co2, temperature, humidity)) {
    Serial.print("Error trying to execute readMeasurement(): ");
    return;
  }

  if (!okTemperature(temperature) || !okHumidity(humidity) || !okCO2(co2)) {
    Serial.println("SCD4X invalid -> restart");
    restartNow("SCD4X data invalid");
  }

  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% RH");
  Serial.print("Co2: "); Serial.print(co2); Serial.println("ppm");
}

// Přečíst data z DS18B20 | Read data from DS18B20
void readDS18B20() {

  // Check if any device is present on the OneWire bus
  if (!oneWire.search(sensorAddress)) {
    oneWire.reset_search();
    Serial.println("Error: Can't find a DS18B20 sensor. Or wrong sensor type!");
    ConfigPortalOnDemand();
  }
  Serial.println("DS18B20 found");

  // Request temperature readings
  DS18B20.requestTemperatures();

  if (!okTemperature(DS18B20.getTempC(sensorAddress))) {
    Serial.println("SHT4x invalid -> restart");
    restartNow("SHT4x data invalid");
  }
  // Fetch temperature in Celsius
  temperature = DS18B20.getTempC(sensorAddress);
  
  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
}

// Přečíst data z SHT4x | Read data from SHT4x
void readSHT4xPlusBMP280() {

  Wire.begin(SDA,SCL);
  delay(200);                                  // Wait for bus to boot in (we have inconsistent results couple times per day without this)

  // SHT4x
  if (!sht4x.begin()) {
    Serial.println("Error: Can't find a SHT4x sensor. Or wrong sensor type!");
    ConfigPortalOnDemand();
  } 
  Serial.println("SHT4x FOUND");
  sht4x.setPrecision(SHT4X_LOW_PRECISION);
  sht4x.setHeater(SHT4X_NO_HEATER);

  sensors_event_t hum, temp;
  sht4x.getEvent(&hum, &temp);

  if (!okTemperature(temp.temperature) || !okHumidity(hum.relative_humidity)) {
    Serial.println("SHT4x invalid -> restart");
    restartNow("SHT4x data invalid");
  }


  temperature = temp.temperature;
  humidity = hum.relative_humidity;
  // BMP280
  if (! bmp.begin(0x77)) {                      // try default address on LaskaKit module    
    Serial.println("Can't find a BMP280 sensor on 0x77 address. Trying 0x76 ..."); 
      if (! bmp.begin(0x76)) {                  // try another address BMP280
        Serial.println("Error: Can't find a BMP280 sensor. Or wrong sensor type!");
        ConfigPortalOnDemand();
      }
  }
  Serial.println("BMP280 FOUND");
  bmp.setSampling(Adafruit_BMP280::MODE_FORCED,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
  delay(10);
  bmp.takeForcedMeasurement();                 // DŮLEŽITÉ

  if (!okPressure(bmp.readPressure() / 100.0F)) {
    Serial.println("BMP280 invalid -> restart");
    restartNow("BMP280 data invalid");
  }

  pressure = bmp.readPressure() / 100.0F;  

  Serial.print("Temp: "); Serial.print(temperature); Serial.println("°C");
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println("% RH");
  Serial.print("Pressure: "); Serial.print(pressure); Serial.println("hPa");
}

void readSensors(){

  switch (sensorType) {
    case 0:               // SHT4x
      Serial.println("Switch case: 0 - SHT4x");
      readSHT4x();
      break;
    case 1:               // BME280
      Serial.println("Switch case: 1 - BME280");
      readBME();
      break;
    case 2:               // SCD4x
      Serial.println("Switch case: 2 - SCD4x");
      readSCD4x();
      break;
    case 3:               // DS18B20
      Serial.println("Switch case: 3 - DS18B20");
      readDS18B20();
      break;
    case 4:               // DS18B20
      Serial.println("Switch case: 4 - SHT4x+BMP280");
      readSHT4xPlusBMP280();
      break;
    default:              // If setted wrong
      Serial.print("Error, sensor value is " + String(sensorType) + ", should be from 0 to 4! ");
      ConfigPortalOnDemand();
      break;
  }
}

// Měření napětí baterie | Battery voltage measurement
void readBat() {
  bat_voltage = analogReadMilliVolts(ADC_PIN) * deviderRatio / 1000;
  Serial.println("Battery voltage: " + String(bat_voltage) + "V");
}

void print_reset_reason(int reason){
  Serial.printf("Reset reason: %d = ", reason);
  switch (reason){
    case 1 : Serial.println ("POWERON_RESET");break;          /**<1,  Vbat power on reset*/
    case 3 : Serial.println ("SW_RESET");break;               /**<3,  Software reset digital core*/
    case 4 : Serial.println ("OWDT_RESET");break;             /**<4,  Legacy watch dog reset digital core*/
    case 5 : Serial.println ("DEEPSLEEP_RESET");break;        /**<5,  Deep Sleep reset digital core*/
    case 6 : Serial.println ("SDIO_RESET");break;             /**<6,  Reset by SLC module, reset digital core*/
    case 7 : Serial.println ("TG0WDT_SYS_RESET");break;       /**<7,  Timer Group0 Watch dog reset digital core*/
    case 8 : Serial.println ("TG1WDT_SYS_RESET");break;       /**<8,  Timer Group1 Watch dog reset digital core*/
    case 9 : Serial.println ("RTCWDT_SYS_RESET");break;       /**<9,  RTC Watch dog Reset digital core*/
    case 10 : Serial.println ("INTRUSION_RESET");break;       /**<10, Instrusion tested to reset CPU*/
    case 11 : Serial.println ("TGWDT_CPU_RESET");break;       /**<11, Time Group reset CPU*/
    case 12 : Serial.println ("SW_CPU_RESET");break;          /**<12, Software reset CPU*/
    case 13 : Serial.println ("RTCWDT_CPU_RESET");break;      /**<13, RTC Watch dog Reset CPU*/
    case 14 : Serial.println ("EXT_CPU_RESET");break;         /**<14, for APP CPU, reseted by PRO CPU*/
    case 15 : Serial.println ("RTCWDT_BROWN_OUT_RESET");break;/**<15, Reset when the vdd voltage is not stable*/
    case 16 : Serial.println ("RTCWDT_RTC_RESET");break;      /**<16, RTC Watch dog reset digital core and rtc module*/
    default : Serial.println ("NO_MEAN");
  }
}

void setup() {
  // Hned vypneme WiFi | disable WiFi, coming from DeepSleep, as we do not need it right away
  WiFi.mode( WIFI_OFF );
  delay( 1 );

  // for board version > 3.5 need to turn uSUP ON
  pinMode(PWR_PIN, OUTPUT);       // Set EN pin for uSUP stabilisator as output
  digitalWrite(PWR_PIN, HIGH);    // Turn on the uSUP power
  delay(200);                   // Wait for uSUP to power up 

  Serial.begin(115200);
  while(!Serial) {} // Wait for serrial ready

  esp_reset_reason_t reset_reason = esp_reset_reason();
  print_reset_reason(reset_reason);

  #ifdef OnDemandPin
    pinMode(OnDemandPin, INPUT);
      // If the OnDemandPin is LOW, start the configuration portal on demand
      if (digitalRead(OnDemandPin) == LOW) {
        ConfigPortalOnDemand();
      }
  #endif

  Serial.println("-------------------");
  Serial.println("LaskaKit Meteo Mini Weather Station");
  Serial.println("TMEP.CZ or EU With EPPROM Settings");
  Serial.println("supporting SHT4x or BME280 or SCD41 or DS18B20 or SHT4x+BMP280");
  Serial.println("board: " + String(board));
  Serial.println("version: " + String(version));
  Serial.println("-------------------");

  eeprom_read();
  // Pripojeni k WiFi | Connect to WiFi
  WiFiConnection();
  readSensors();
  readBat();

  postData();

  WiFi.disconnect(true);
  GoToSleep("end data posting");
}

void loop() {
  // Nepotřebujeme loop | We dont use the loop
}