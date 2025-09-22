# Návod na stavbu venkovní Wi-Fi meteostanice s Meteo Mini

Přemýšlíš o výrobě své vlastní domácí meteostanice?  
Nachystali jsme pro tebe kompletní kit obsahující radiační štít, krabičku, držák štítu, spojovací materiál a naši vývojovou desku Meteo Mini, kterou jednoduše naprogramuješ pomocí Arduino IDE.

![LaskaKit WeatherStation kit](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/LaskaKitMeteo.JPG)

Obsahuje modul ESP32-C3-mimi založený na Wi-Fi čipu ESP32-C3, je osazen konektorem pro připojení I²C čidel.  
Meteostanice je napájena z LiPol akumulátoru, který je připojen pomocí konektoru na základní desce.  

Pro ještě větší jednoduchost zapojení je deska připravena na osazení interního teplotního čidla DALLAS DS18B20 a nechybí náš populární konektor μŠup pro snadné připojení dalších čidel se sběrnicí I²C.  
Deska má také integrovanou nabíječku akumulátoru, takže může být akumulátor nabíjen z USB-C konektoru nebo solárního panelu se jmenovitým napětím 5–10 V.  
Pro ten je na základní desce rovněž osazen konektor. Na desce je též osazený dělič napětí, který je připojen k akumulátoru a jeho výstup je připojen na ADC vstup mikrokontroléru. Stav akumulátoru tak bude neustále pod dohledem.  

---

## Součásti kitu

![LaskaKit Meteo Mini](https://github.com/LaskaKit/Weather_Station_Mini/blob/main/img/2.jpg)

- 1 ks – Základní deska LaskaKit Meteo Mini V4 IPEX  
- 1 ks – Anténa 5dBi 19cm 2.4G  
- 1 ks – Pigtail MHF3/IPEX3 - SMA Female, kabel 15cm  
- 1 ks – GeB LiPol Baterie 801454 580mAh 3.7V JST-PH 2.0  
- 1 ks – Solární panel 5V 4W s držákem na zeď  
- 1 ks – μŠup, STEMMA QT, Qwiic JST-SH 4-pin kabel - 10cm  
- 1 ks – Senzor SHT40 nebo SHT40+BMP280 (podle varianty kitu)  
- 1 ks – Kryt pro čidla meteostanice, 70x145mm, plast  
- 3 ks – Páska vázací 3,6x300 mm černá (z balení 100 ks)  
- 1 ks – Šroub do plastu 3,5×12 BN 82428 ZB  
- 2 ks – Šroub M3×24  
- 2 ks – Šroub do plastu 2,2×5 BN 82428  
- 4 ks – Šroub do plastu 2,2×10 BN 82428  

---

## Návod k použití

V našem detailním návodu na stavbu meteostanice s Meteo Mini najdeš vše od sestavení, přes naprogramování až po nastavení.  
V ukázkovém kódu používáme **WiFi Manager**, který slouží pro prvotní konfiguraci celé meteostanice.  

Stačí připojit akumulátor k Meteo Mini, vyhledat WiFi síť, kterou Meteo Mini vytvoří, přihlásit se (AP: `LaskaKitMeteo`) a nastavit tvou domácí Wi-Fi síť.  

---

🔗 Odkaz na stavebnici: https://www.laskakit.cz/laskakit-meteo-mini-meteostanice/