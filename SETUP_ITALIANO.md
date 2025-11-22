# 🇮🇹 Guida Setup T-Watch S3 - Italiano

## Hai un T-Watch con queste caratteristiche:
- **Chip**: ESP32-S3
- **PMU**: AXP2101
- **Display**: ST7789V 1.54" (240x240)
- **LoRa**: SX1262
- **Motore Aptico**: DRV2605
- **Accelerometro**: BMA423

---

## 📋 PROCEDURA COMPLETA

### STEP 1: Verifica Arduino IDE
Devi avere **Arduino IDE 2.x** installato.
Se hai ancora la vecchia versione 1.8.x, scarica la nuova da: https://www.arduino.cc/en/software

### STEP 2: Installa ESP32 Board Support
1. Apri Arduino IDE
2. File → Preferences
3. In "Additional Boards Manager URLs" aggiungi:
   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```
4. Tools → Board → Boards Manager
5. Cerca "esp32"
6. Installa **ESP32 by Espressif Systems versione 2.0.9**
   ⚠️ IMPORTANTE: Usa esattamente la 2.0.9, non versioni più recenti!

### STEP 3: Installa le Dipendenze
Hai due opzioni:

#### Opzione A - Automatica (Consigliata)
1. Apri un Prompt dei Comandi
2. Naviga alla directory del progetto:
   ```
   cd C:\Users\devel\source\repos\TTGO_TWatch_Library
   ```
3. Esegui lo script:
   ```
   install_deps.bat
   ```

#### Opzione B - Manuale
1. Scarica: https://github.com/Xinyuan-LilyGO/T-Watch-Deps
2. Copia tutte le cartelle dentro in:
   ```
   C:\Users\devel\Documents\Arduino\libraries\
   ```
   Le cartelle da copiare sono:
   - arduinoFFT
   - ESP8266Audio
   - IRremoteESP8266
   - lvgl
   - RadioLib
   - SensorLib
   - TFT_eSPI
   - TinyGPSPlus
   - XPowersLib

### STEP 4: Configura Arduino IDE
Apri Arduino IDE e configura in Tools:

```
Board: "ESP32S3 Dev Module"
USB CDC On Boot: "Enable"
CPU Frequency: "240MHz (WiFi)"
USB DFU On Boot: "Disabled"
Flash Mode: "QIO 80MHz"
Flash Size: "16MB (128Mb)"
PSRAM: "OPI PSRAM"
Partition Scheme: "16M Flash (3MB APP/9.9MB FATFS)"
Upload Mode: "UART0/Hardware CDC"
Upload Speed: "921600"
USB Mode: "Hardware CDC and JTAG"
```

### STEP 5: Apri l'esempio Factory
1. File → Examples → TTGO_TWatch_Library → demo → factory
2. Il file si aprirà con il codice pronto

### STEP 6: Modifica SX1262 nel Factory Demo
Nel file `factory.ino`, assicurati che sia decommentato:
```cpp
#define USE_RADIO_SX1262
```
E che gli altri radio siano commentati:
```cpp
// #define USE_RADIO_SX1280
// #define USE_RADIO_CC1101
```

### STEP 7: Upload sul T-Watch
1. Collega il T-Watch via USB
2. Seleziona la porta COM corretta in Tools → Port
3. Premi il pulsante Upload (freccia →)

⚠️ **Se l'upload fallisce:**
1. Premi il bottone corona del watch per 1 secondo (accende il device)
2. Se continua a fallire, segui la procedura di boot manuale:
   - Rimuovi il retro del watch
   - Premi e tieni premuto il tasto BOOT (vedi immagine in images/BUTTON.jpg)
   - Premi corona per 1 secondo
   - Rilascia tutto
   - Prova upload

---

## 🎯 ESEMPI DISPONIBILI

### Demo Completa
**demo → factory**: Test completo di tutto l'hardware
- Display touchscreen
- LoRa SX1262
- Accelerometro
- Motore aptico
- RTC
- Audio/Speaker
- IR Sender
- WiFi

### GUI Completa
**demo → LilyGoGui**: Interfaccia utente completa con:
- Watchface
- Menu applicazioni
- Lettura sensori
- Gestione batteria

### Esempi LVGL
**lvgl → widgets**: Interfacce grafiche moderne
- Bottoni, slider, grafici
- Animazioni
- Temi personalizzabili

### Radio LoRa
**radio → SX1262**: Comunicazione LoRa
- Trasmissione/ricezione
- Range: fino a diversi km!

---

## ❓ ERRORI COMUNI

### "LilyGoLib.h: No such file or directory"
Hai dimenticato di installare la libreria TTGO_TWatch_Library.
Soluzione: Sketch → Include Library → Add .ZIP Library → seleziona il repository

### "TFT_eSPI user setup not defined"
La libreria TFT_eSPI non è configurata correttamente.
Soluzione: Reinstalla le dipendenze con lo script install_deps.bat

### "esp_vad.h: No such file or directory"
Stai usando una versione ESP32 sbagliata.
Soluzione: Usa ESP32 2.0.9 esattamente (non 2.0.14 o 3.x)

### Upload fallisce / COM port non appare
Il watch è spento.
Soluzione: Premi il bottone corona per 1 secondo

### Schermo nero dopo upload
USB CDC On Boot non è abilitato.
Soluzione: Tools → USB CDC On Boot → Enable

---

## 📚 RISORSE

- Repository principale: https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library
- Branch T-Watch S3: https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library/tree/t-watch-s3
- Video YouTube setup: https://www.youtube.com/watch?v=RCYUN5yAnUk
- Pinout e utilities: `src/utilities.h`

---

## 🔋 INFO BATTERIA

⚠️ **IMPORTANTE**: La corrente di carica predefinita è 125mA.
NON aumentarla oltre 125mA o danneggerai la batteria!

Compatibile con batterie 502530 (5x25x30mm)

---

Buon divertimento con il tuo T-Watch S3! 🚀
