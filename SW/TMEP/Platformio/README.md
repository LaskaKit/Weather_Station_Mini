# Versatile code used for TMEP.CZ(.EU) together with Meteo Mini ESP32-C3 and sensors.
###  Description: After the uploading, WiFi manager will create an AP: LaskaKit Meteo Config
Connect to this AP through smart phone or laptop. Also, you have to: 
- fill Subdomain,
- choose Domain: TMEP.CZ or EU,
- fill How long you want the weather station to sleep in minutes,
- choose sensor, now are available: 
    + SHT40: (0x44) or (0x45), 
    + BME280: (0x77),
    + SCD41, 
    + DS18B20, 
    + SHT4x+BMP280. 