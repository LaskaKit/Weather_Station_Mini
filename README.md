# Outdoor weather station with LaskaKit Weather Station Mini v3 - complete kit

Are you thinking of making your own home weather station? We have prepared a complete kit for you, including a radiation shield, box, sensors, shield mount, fasteners and our [Meteo Mini development board](https://www.laskakit.cz/laskakit-meteo-mini/), which you can easily program using Arduino IDE.

<img width="1024" height="768" alt="image" src="https://github.com/user-attachments/assets/30620a8c-4628-4c0d-a87b-d714b234e26e" />

It contains a ESP32-C3-mini module based on the ESP32-C3 Wi-Fi chip. The board is equipped with μŠup connectors for connecting I2C, SPI and IO sensors. The weather station is powered by a LiPol battery, which is connected via a JST-PH-2 connector on the Meteo Mini.
In addition, the board has an integrated Li-Pol battery charger so the battery can be charged from the USB-C connector or a solar panel with a nominal voltage of 5-10V. A JST-PH-2 connector for the latter is also fitted on the board. Finally, there is a voltage divider on the board which is connected to the battery and its output is connected to the ADC input of the microcontroller, allowing you to constantly monitor the battery's charge.

![LaskaKit Meteo Mini](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)<br/>

If you're worried about the assembly proccess, don't be. Our simple yet detailed build guide (found in Weather_Station_Mini/Manual/) covers everything from the physical assembly to programming and configuration. In fact, our WiFi Manager-enabled sample code allows you to just plug the battery into the Meteo Mini, find the WiFi transmitted by the Meteo Mini, log in (SSID: LaskaKitMeteo), set up your home WiFi network and you're done.

Link to Weather Station kit [https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/](https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/)
