# Návod na stavbu venkovní Wi-Fi 
nice s Meteo Mini
Přemýšlíte o výrobě své vlastní [domácí meteostanice](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/)? Nachystali jsme pro vás kompletní kit obsahující radiační štít, krabičku, držák štítu, naší vývojovou desku [Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini/), kterou jednoduše naprogramujete v Arduino a samozřejmě šroubky a matičky k přichycení. 

## 3D tištěné části meteostanice
U nás můžete zakoupit i 3D tištěné krabičky, pokud si je chcete vytisknout sami, můžete. Modely najdete na našem [github](https://github.com/LaskaKit/Weather_Station_Mini/tree/main/3D).

Pokud si je chcete vytisknout sami, doporučujeme následující postup.

Holder tiskněte takto s podpěrami. 

![Držák na radiační štít](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/18.jpg)

Infill 20% je dostatečný.

![Nastavení tisku](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/19.jpg)

Solar bracket tiskněte naplocho.

![Držák na solární panel](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/20.jpg)

Box BOTTOM a TOP tiskněte takto a s podpěrami.

![Krabička](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/21.jpg)

S tímto doporučením vytisknete krabičky s nejlepšími výsledky. 

A teď můžeme přejít k samotnému návodu stavby  [Wi-Fi meteostanice](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/). 

## Solární panel

Začneme s držákem solárního panelu.

![1](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/1.jpg)

Vložíme matky do držáku solárního panelu.

![2](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)

Na druhou stranu držáku solárního panelu připevníme první část držáku mezi solárním panelem a radiačním štítem.

![3](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/3.jpg)

Šroubky jsou zašroubovány do matek, které jsou zasunuty na drhé straně držáku.

![4](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/4.jpg)


Skrze otvor držáku solárního panelu protáhneme přívodní kabel k samotnéu solárnímu panelu a zapájíme.
Červený kabel na +, černý na -.

![5](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/5.jpg)

Solární panel můžeme zasunout do držáku.

![6](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/6.jpg)

## Meteo Mini a krabička

Nyní přejdeme k vývojové desce [Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini/) z naší vlastní díly. O Meteo Mini jsme se rozepsali na našem [github](https://github.com/LaskaKit/Meteo_Mini). V zkratce můžeme desku připomenout.
Obsahuje [Wi-Fi modul ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/), je osazen konektor pro připojení I2C čidla, osadit můžete i čidlo s 1-wire sběrnicí (například DS18B20). Venkovní meteostanice je napájena z [LiPol akumulátoru](https://www.laskarduino.cz/baterie-a-akumulatory/), který je připojen přes konektor. Akumulátor může být nabíjen z microUSB konektoru nebo solárního panelu s 5V či 6V jmenovitým napětím. 

Deska s Wi-Fi modulem [ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/) má osazený i dělič napětí, který je připojen k akumulátoru. Stav akumulátoru tak budete mít neustále pod dohledem. 

![7](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/7.jpg)

K vaší meteostanici s Wi-Fi čipem ESP8266 v [modulu ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/) můžete připojit například čidlo teploty, vlhkosti a tlaku [BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/).
Kabely konektoru můžete buď přímo zapájet nebo použít pinovou lištu.

Kromě toho čidla můžete použít i jiné, například [čidlo vlhkosti a teploty SHT30](https://www.laskarduino.cz/senzor-teploty-a-vlhkosti-vzduchu-sht30/). Vylepšit stanici můžete třeba i [dešťový senzor](https://www.laskarduino.cz/destovy-senzor/). 

Dalším sběrnicí na kterou můžete připojit čidlo je 1-wire. Jedná se o třívodičovou sběrnici, ke které můžete zapájet přímo čidlo teploty [DS18B20](https://www.laskarduino.cz/dallas-digitalni-cidlo-teploty-ds18b20--to-92/) nebo zapájíte jenom kabel [vodotěsné verze čidla DS1820](https://www.laskarduino.cz/dallas-digitalni-vodotesne-cidlo-teploty-ds18b20-1m/) a čidlo připevníte jinam. 

![8](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/8.jpg)

Krabičku a čidlo připevníme ke krabičce.

![9](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/9.jpg)

Kabel od akumulátoru nevedeme skrze otvor v krabičce. Akumulátor přilepte na druhou stranu krabičky s deskou s [Wi-Fi modulem ESP12F](https://www.laskarduino.cz/ai-thinker-esp-12f-esp8266-ce-wifi-modul/).

Nyní budeme pokračovat s přípravou radiačního štítu. 

V sadě Wi-Fi meteostanice dostanete i radiační štít - ten kryje jak čidlo před povětrnostními vlivy, tak i krabičku s deskou [Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini/).

## Radiační štít

V radiačním štítu máte vyvrtaný otvor pro přišroubování druhé části držáku solárního panelu.

![10](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/10.jpg)

Zašroubujeme jej. 

![11](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/11.jpg)

I do tohoto držáku vložíme přiložené matky.

![12](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/12.jpg)

## Kompletace
Přišroubujeme držák solárního panelu k radiačnímu štítu.

![13](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/13.jpg)

Kabely ze solárního vodiče vedeme skrz otvor krabičce desky [Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini/).

![14](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/14.jpg)

Obě části krabičky s [Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini/) a [LiPol akumulátorem](https://www.laskarduino.cz/baterie-a-akumulatory/) sešroubujeme. 

![15](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/15.jpg)

Do spodní části radiačního štítu vložíme krabičku s Meteo Mini a čidlem. V tomto příkladu s [čidlem tlaku, vlhkosti a teploty BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/).

![16](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/16.jpg)

Abychom mohli meteostanici připevnit k nějaké tyči dostatečně daleko od povrchu země a fasády domu, můžeme použít poslední 3D výtisk - držák. 
Ten přišroubujeme skrze krabičku až do radiačního štítu. 

![17](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/17.jpg)

A tím jsme se dostali na konec našeho návodu. 

## Vzorový kód

Pro [venkovní meteostanici](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/) jsme vytvořili i [vzorový kód (github)](https://github.com/LaskaKit/Weather_Station_Mini), kde používáme jak čidlo tlaku, teploty a vlhkosti [BME280](https://www.laskarduino.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/), dále čidlo teploty DS18B20 a zároveň měříme napětí na [LiPol akumulátoru](https://www.laskarduino.cz/baterie-a-akumulatory/).
Všechna data odesíláme na službu Thingspeak.  

## Rady a tipy

Při umístění [venkovní meteostanice s Meteo Mini](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/) dbejte opatrnosti - vyhněte se místům, kde by mohlo vznikat sálavé teplo - fasáda, asfalt. 
Díky solárnímu panelu můžete bude meteostanice v případě vybití dobita. [Meteostanice](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/) by tak měla být i na slunném místě.

Pokud máte možnost, umístěte meteostanici ve výšce 2m nad například travnatou plochu daleko od domu. Tím si zajístíte nejpřesnější měření.

Odkaz na stavebnici naleznete na [https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/)
