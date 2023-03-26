
# Návod na stavbu venkovní Wi-Fi meteostanice s Meteo Mini
Přemýšlíš o výrobě své vlastní domácí meteostanice? Nachystali jsme pro tebe [kompletní kit](https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/) obsahující radiační štít, krabičku, držák štítu, spojovací materiál a naší vývojovou desku [Meteo Mini](https://www.laskakit.cz/laskakit-meteo-mini/), kterou jednoduše naprogramuješ pomocí Arduino IDE.<br/>
<br/>
![LaskaKit WeatherStation kit](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/LaskaKitMeteo.JPG)<br/>
<br/>
Obsahuje modul ESP-C3-12F založený na Wi-Fi čipu ESP32-C3, je osazen konektorem pro připojení I2C čidel. Meteostanice je napájena z LiPol akumulátoru, který je připojen pomocí konektoru na základní desce.<br/>
Pro ještě větší jednoduchost zapojení je deska připravena na osazení interního teplotního čidla DALLAS DS18B20 a nechybí náš populární konektor μŠup pro snadné 
připojení dalších čidel se sběrnicí I2C. Deska má také integrovanou nabíječku akumulátoru a tak může být akumulátor nabíjen z USB-C konektoru, 
nebo solárního panelu se jmenovitým napětím 5-6V. Pro ten je na základní desce rovněž osazen konektor. Na desce je též osazený dělič napětí, který je připojen k akumulátoru a jeho výstup je připojen na ADC vstup mikrokontroléru. Stav akumulátoru tak bude neustále pod dohledem. <br/>
Kit obsahuje všechny potřebné komponenty:<br/>
<br/>
![LaskaKit Meteo Mini](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)<br/>
● 1 ks – [Základní deska LaskaKit Meteo Mini](https://www.laskakit.cz/laskakit-meteo-mini/) (buď PCB antena pro integrovanou anténu nebo IPEX pro 
externí)<br/>
● 1 ks – [Senzor tlaku, teploty a vlhkosti LaskaKit BME280](https://www.laskakit.cz/arduino-senzor-tlaku--teploty-a-vlhkosti-bme280/)<br/>
● 1 ks – [Baterie GeB LiPol Baterie 603048 900mAh 3.7V JST-PH 2.0](https://www.laskakit.cz/ehao-lipol-baterie-603048-900mah-3-7v/)<br/>
● 1 ks – [Solární panel 5V 4W s držákem na zeď](https://www.laskakit.cz/solarni-panel-5v-4w-s-drzakem-na-zed/)<br/>
● 1 ks – [Napájecí kabel JQ-118 USB-C do JST-PH-2 2mm 10cm](https://www.laskakit.cz/napajeci-kabel-jq-118j-usb-c-do-jst-ph-2-2mm-10cm/)<br/>
● 1 ks – [μŠup, STEMMA QT, Qwiic JST-SH 4-pin kabel - 10cm](https://www.laskakit.cz/--sup--stemma-qt--qwiic-jst-sh-4-pin-kabel-10cm/)<br/>
● 1 ks – [Kryt pro čidla meteostanice, 70x145mm, plast](https://www.laskakit.cz/kryt-pro-cidla-meteostanice--70x145mm--plast/)<br/>
● 1 ks – [Anténa 3.0dBi 11.5cm 2.4G](https://www.laskakit.cz/antena-10cm-2-4g/) + Pigtail RF240 (v případě externí antény)<br/>
● 6 ks – Šroub M2.2x5 (přichycení čidla a desky do krabičky)<br/>
● 1 ks – Šroub M3.5x12 (volitelné přichycení soláru na radiační štít)<br/>
● 4 ks – Šroub M2.2x16 (přichycení vrchního krytu krabičky)<br/>
● 2 ks – Šroub M3x20 (přichycení krabičky s držákem do radiačního štítu)<br/>
● 3 ks – Páska vázací 3,6x300 mm černá<br/>
<br/>
V našem opravdu detailním návodu na stavbu meteostanice s Meteo Mini najdeš jak základní informace o sestavení a naprogramování až po nastavení. V našem vzorovém kódu totiž používáme WiFi Manager, který je použitý pro prvotní nastavení celé meteostanice. Stačí tak zapojit do Meteo Mini akumulátor, vyhledat WiFi síť, kterou Meteo Mini vytvřoí, přihlásit se (AP: LaskaKitMeteo, Heslo: meteostation) a nastavit tvou domácí Wi-Fi síť a je hotovo.<br/>
Odkaz na stavebnici najdeš na [https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/](https://www.laskarduino.cz/laskakit-meteo-mini-meteostanice/)<br/>
<br/>
![LaskaKit WeatherStation kit](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/LaskaKitMeteo.JPG)<br/>
