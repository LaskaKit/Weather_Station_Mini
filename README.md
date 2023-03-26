# Outdoor weather station with LaskaKit Weather Station Mini - complete kit

Are you thinking of making your own home weather station? We have prepared a complete kit for you, including a radiation shield, box, shield holder, fasteners and our [Meteo Mini development board](https://www.laskakit.cz/laskakit-meteo-mini/), which you can easily program using the Arduino IDE.

![LaskaKit WeatherStation kit](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/LaskaKitMeteo.JPG)

It contains the ESP-C3-12F module based on the ESP32-C3 Wi-Fi chip, and is assembled with a connector for connecting I2C sensors. The weather station is powered by a LiPol battery, which is connected via a connector on the Meteo Mini.
For even greater simplicity of connection, the board is ready to accommodate the internal DALLAS DS18B20 temperature sensor and our popular μŠup connector for easy connection of other I2C bus sensors. The board also has an integrated battery charger so the battery can be charged from the USB-C connector or a solar panel with a nominal voltage of 5-6V. A connector for the latter is also fitted on the motherboard. There is also a voltage divider on the board which is connected to the battery and its output is connected to the ADC input of the microcontroller. The status of the battery will thus be under constant surveillance.

![LaskaKit Meteo Mini](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)<br/>

n our really detailed instructions for building a weather station with the Meteo Mini, you will find basic information on how to build and program it, right through to the settings. In fact, in our sample code we use WiFi Manager, which is used for the initial setup of the entire weather station. So just plug the battery into the Meteo Mini, find the WiFi network that the Meteo Mini will create, log in (AP: LaskaKitMeteo, Password: meteostation) and set up your home WiFi network and you're done.

Link to Weather Station kit [https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/)






