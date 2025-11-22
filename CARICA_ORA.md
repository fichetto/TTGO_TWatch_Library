# 🚀 CARICA IL FACTORY DEMO ADESSO!

## ✅ Librerie installate con successo!
Tutte le dipendenze sono state copiate in: `C:\Users\devel\Documents\Arduino\libraries\`

## 📱 T-Watch rilevato su: **COM4**

---

## 🎯 PROCEDURA IMMEDIATA - Segui questi passi:

### 1. Apri Arduino IDE

### 2. Vai su:
```
File → Apri → C:\Users\devel\source\repos\TTGO_TWatch_Library\examples\demo\factory\factory.ino
```

### 3. Configura le impostazioni in Tools (copia ESATTAMENTE):

```
Board:                    "ESP32S3 Dev Module"
Port:                     "COM4"  ⬅️ IMPORTANTE!
USB CDC On Boot:          "Enable"
CPU Frequency:            "240MHz (WiFi)"
Core Debug Level:         "None" (o "Verbose" per debug)
USB DFU On Boot:          "Disabled"
Flash Mode:               "QIO 80MHz"
Flash Size:               "16MB (128Mb)"
PSRAM:                    "OPI PSRAM"
Partition Scheme:         "16M Flash (3MB APP/9.9MB FATFS)"
Upload Mode:              "UART0/Hardware CDC"
Upload Speed:             "921600"
USB Mode:                 "Hardware CDC and JTAG"
```

### 4. Clicca sul pulsante UPLOAD (freccia →)

### 5. Aspetta la compilazione e l'upload

---

## 🎉 Cosa aspettarti dopo l'upload:

Il T-Watch mostrerà una **interfaccia demo completa** con:

1. **Watchface con orologio** - Mostra ora, batteria, data
2. **Menu touchscreen** - Swipe per navigare
3. **Test accelerometro** - Muovi il polso
4. **WiFi Scanner** - Scansiona reti WiFi
5. **LoRa Radio** - Test trasmissione SX1262
6. **Vibrazione** - Test motore aptico DRV2605
7. **IR Remote** - Test sensore infrarossi
8. **Microfono/Audio** - Registrazione e playback
9. **Batteria** - Livello carica e info PMU

---

## ❓ Problemi comuni:

### Upload fallisce / "Failed to connect"
1. Premi il **bottone corona** per 1 secondo (accende il watch)
2. Riprova upload

### "Sketch too big"
- Hai selezionato la partition scheme sbagliata
- Deve essere: **16M Flash (3MB APP/9.9MB FATFS)**

### "LilyGoLib.h not found"
- Riavvia Arduino IDE per caricare le nuove librerie

### Schermo resta nero dopo upload
- USB CDC On Boot deve essere **Enable**

---

## 🎮 Dopo il successo, prova anche:

1. **LilyGoGui** (`examples/demo/LilyGoGui/`) - GUI completa tipo smartwatch
2. **SimpleWatch** - Se vuoi qualcosa più semplice da modificare
3. **SX1262 LoRa** (`examples/radio/SX1262/`) - Comunicazione wireless

---

## 📊 Info Hardware del tuo T-Watch S3:

- Chip: **ESP32-S3**
- Display: **ST7789V 240x240**
- Touch: **FT6236U**
- LoRa: **SX1262** ✅
- PMU: **AXP2101**
- Accelerometro: **BMA423**
- Motore Aptico: **DRV2605**
- RTC: **PCF8563**
- Porta USB: **COM4** ✅

---

🚀 **VAI E CARICA!** 🚀
