# Tutorial "How to assembly own outdoor weather station with LaskaKit Weather Station Mini"

Are you looking for a DIY outdoor Wi-Fi weather station? Let's check this tutorial where we will show you how to build [own outdoor weather station](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/) moreover with Wi-Fi connectivity. We prepared complete kit which contains radiation shield, enclosure, holder of shield and our development board called  [LaskaKit Weather Station Mini](https://www.laskarduino.cz/laskakit-meteo-mini/), which you may easily programmed in Arduino.

## 3D printed parts
For sure, you can buy whole kit which contains 3D printed parts. In case you need more of them, you may print it yourself. 3D models are available on our [github](https://github.com/LaskaKit/Weather_Station_Mini/tree/main/3D).

If you want to print yourself, we are recommending this procedure.

Print the holder Holder with supports.

![Holder of radiation shield](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/18.jpg)

Infill set to 20% is enough for mechanical stress.

![Print settings](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/19.jpg)

Solar bracket print like this.

![Solar panel holder](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/20.jpg)

The enclosure BOTTOM and TOP print like this with supports.

![The enclosure](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/21.jpg)

With this recommendation, the 3D printed parts are the best quality.

And now we may move to assemble of [outdoor weather station](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/).

## Solar panel

Let's start with solar panel holder.

![1](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/1.jpg)

Put nuts to the solar panel holder.

![2](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)

On the second side, attach the solar panel holder and holder of radiation shield.

![3](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/3.jpg)

Bolts are in nuts which are put on the second side.

![4](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/4.jpg)

The wires pass through the hole of solar panel holder and solder it.
Red wire to +, black wire to -.

![5](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/5.jpg)

You may slide to holder.

![6](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/6.jpg)

## Weather Station Mini and enclosure

Now we may check our development board called [Weather Station Mini](https://www.laskarduino.cz/laskakit-meteo-mini/) from our lab. You may also see the [github](https://github.com/LaskaKit/Meteo_Mini) of Weather Station Mini.
The board contains [Wi-Fi module ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/), it is assembled by connector for I2C bus, you may also use sensor with 1-wire bus (e.i. DS18B20). Outdoor weather station is powered from [LiPol battery](https://www.laskardu0no.cz/baterie-a-akumulatory/), which is connected by JST-PH connector. The battery may be charged from microUSB connector or 6V solar panel.

¨The board with Wi-Fi module [ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/) has voltage divider on board connected to battery.

![7](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/7.jpg)

You may use as a sensor of pressure, temperature and humidity for example [BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/).
You may solder the wires or use male pin header.

Except of this sensor, you may also use [sensor of temperature and humidty SHT30](https://www.laskarduino.cz/senzor-teploty-a-vlhkosti-vzduchu-sht30/).

Next bus which is available on board is 1-wire bus. It is three wires bus where you can connect sensor of temperature and humidty [DS18B20](https://www.laskarduino.cz/dallas-digitalni-cidlo-teploty-ds18b20--to-92/) or solder the cable or [waterproof version of DS1820](https://www.laskarduino.cz/dallas-digitalni-vodotesne-cidlo-teploty-ds18b20-1m/).

![8](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/8.jpg)

Connect the Weather Mini board and sensor to enclosure.

![9](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/9.jpg)

Now we will continue with radiation shield.

The radation shield is pressent in the outdoor Weather Station Mini kit.

## Radiation shield

On the TOP of the radiation shield is hole for screw on the second part of solar panel holder.

![10](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/10.jpg)

Screw it.

![11](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/11.jpg)

Puth nuts to this holder.

![12](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/12.jpg)

## Completion
Screw the holder and solar panel holder to radiation shield.

![13](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/13.jpg)

The wires pass through holde in the enclosure of [Weather Station Mini](https://www.laskarduino.cz/laskakit-meteo-mini/).

![14](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/14.jpg)

Screw the both part of the enclosure with [Weather Station Mini](https://www.laskarduino.cz/laskakit-meteo-mini/) and [LiPol battery](https://www.laskarduino.cz/baterie-a-akumulatory/).

![15](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/15.jpg)

Put the enclosure with Weather Station Mini to radiation shield. In this tutorial we are using [sensor of pressure, temperature and humidity BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/).

![16](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/16.jpg)

The radiation shield should be placed on rod, where it would be far from surface and facade of the house. Screw the Weather Station mini enclosure to the radiation shield. 

![17](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/17.jpg)

And that's the end of our tutorial.

## Example code

We wrote an [example code (github)](https://github.com/LaskaKit/Weather_Station_Mini) for [outdoor weather station](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/) where we are using sensor of temperature, humidity and pressure sensor [BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), temperature sensor DS18B20 and Wi-Fi moudule is measuring the voltage of [LiPol battery](https://www.laskarduino.cz/baterie-a-akumulatory/).
Data is sent to Thingspeak. 

Link to Weather Station kit [https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/)






