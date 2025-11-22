# 🚀 PlatformIO Quick Start - T-Watch S3

## ✅ TUTTO GIÀ CONFIGURATO!

Il progetto è pronto, il Factory Demo è già selezionato in `platformio.ini`!

---

## 🎯 3 SEMPLICI PASSI:

### 1️⃣ Apri il progetto in VSCode
```
File → Open Folder → C:\Users\devel\source\repos\TTGO_TWatch_Library
```

### 2️⃣ Compila
Clicca sull'icona **✓** (checkmark) nella barra in basso di VSCode
oppure
```
Ctrl+Alt+B
```

### 3️⃣ Carica sul T-Watch (COM4)
Clicca sull'icona **→** (freccia) nella barra in basso di VSCode
oppure
```
Ctrl+Alt+U
```

---

## 📊 Configurazione attuale (già pronta):

```ini
[platformio.ini]
src_dir = examples/demo/factory    ✅ Factory Demo attivo
board = LilyGoWatch-S3             ✅ Board corretta
upload_speed = 921600              ✅ Velocità ottimizzata
monitor_speed = 115200             ✅ Serial monitor
```

**Dipendenze** (si installano automaticamente):
- ✓ ESP8266Audio
- ✓ IRremoteESP8266
- ✓ RadioLib (con SX1262)
- ✓ TFT_eSPI
- ✓ LVGL 8.4.0
- ✓ XPowersLib (PMU AXP2101)
- ✓ SensorLib (BMA423)
- ✓ TinyGPSPlus

---

## 🎮 Cambiare Esempio (Opzionale)

Per provare altri esempi, modifica la riga 144 di `platformio.ini`:

### Demo Completa GUI
```ini
src_dir = examples/demo/LilyGoGui
```

### LoRa SX1262 - Trasmissione
```ini
src_dir = examples/radio/SX1262/SX126x_Transmit
```

### LoRa SX1262 - Ricezione
```ini
src_dir = examples/radio/SX1262/SX126x_Receive
```

### LoRa PingPong (test 2 dispositivi)
```ini
src_dir = examples/radio/SX1262/SX126x_PingPong
```

### Orologio TFT semplice
```ini
src_dir = examples/display/TFT_Clock
```

### LVGL Widgets (UI moderna)
```ini
src_dir = examples/lvgl/widgets/btn
```

### Accelerometro BMA423
```ini
src_dir = examples/sensor/BAM423_Accelerometer
```

### Sleep e Wakeup
```ini
src_dir = examples/sleep/WakeupFromTouchScreen
```

Dopo ogni modifica: salva, ricompila e carica!

---

## 🔧 Comandi PlatformIO Utili:

### Terminal integrato VSCode:
```bash
# Compila
pio run

# Compila e carica
pio run --target upload

# Monitor seriale
pio device monitor

# Upload + monitor (comodo!)
pio run --target upload && pio device monitor

# Pulisci build
pio run --target clean
```

---

## 📱 Monitorare il Serial Output

Dopo l'upload, clicca l'icona **🔌** (plug) in basso per vedere:
- Log di debug
- Info WiFi scan
- Dati LoRa
- Letture sensori
- Errori eventuali

Oppure da terminale:
```bash
pio device monitor
```

Per uscire: `Ctrl+C`

---

## ⚡ Vantaggi di PlatformIO vs Arduino IDE:

✅ Dipendenze automatiche (no installazione manuale)
✅ Configurazione version-controlled
✅ Build più veloce
✅ IntelliSense migliore
✅ Debugging integrato
✅ Multi-progetto facile
✅ Terminal integrato

---

## 🎯 Quick Commands Toolbar (barra in basso VSCode):

```
🏠 Home
✓  Build (compile)
→  Upload
🗑️  Clean
🔧 Test
🔌 Serial Monitor
🔁 Upload & Monitor
```

---

## 🚀 FAI COSÌ ADESSO:

1. Apri VSCode
2. Open Folder → questo progetto
3. Clicca **✓** (compila - circa 1-2 minuti la prima volta)
4. Clicca **→** (upload - circa 30 secondi)
5. Clicca **🔌** (monitor per vedere output)

FATTO! Il Factory Demo partirà automaticamente sul T-Watch! 🎉

---

## 📦 Struttura Progetto PlatformIO:

```
TTGO_TWatch_Library/
├── platformio.ini          ← Configurazione principale
├── examples/               ← Tutti gli esempi
│   ├── demo/
│   │   ├── factory/       ← Attivo ora
│   │   └── LilyGoGui/
│   ├── radio/
│   ├── lvgl/
│   └── ...
├── src/                    ← Libreria core T-Watch
├── board/                  ← Definizione board custom
└── .pio/                   ← Build cache (autogenerato)
```

---

Buon divertimento! 🔥
