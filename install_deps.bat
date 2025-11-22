@echo off
echo ============================================
echo T-Watch S3 - Installazione Dipendenze
echo ============================================
echo.

set ARDUINO_LIB_PATH=C:\Users\devel\Documents\Arduino\libraries
set TEMP_DEPS=C:\temp\T-Watch-Deps

echo Verifico directory Arduino libraries...
if not exist "%ARDUINO_LIB_PATH%" (
    echo Creazione directory %ARDUINO_LIB_PATH%...
    mkdir "%ARDUINO_LIB_PATH%"
)

echo.
echo Download T-Watch-Deps da GitHub...
cd C:\temp
if exist T-Watch-Deps (
    echo Directory gia' esistente, rimuovo...
    rmdir /S /Q T-Watch-Deps
)

git clone https://github.com/Xinyuan-LilyGO/T-Watch-Deps.git

echo.
echo Copiatura librerie in %ARDUINO_LIB_PATH%...
echo.

xcopy /E /I /Y "%TEMP_DEPS%\arduinoFFT" "%ARDUINO_LIB_PATH%\arduinoFFT"
xcopy /E /I /Y "%TEMP_DEPS%\ESP8266Audio" "%ARDUINO_LIB_PATH%\ESP8266Audio"
xcopy /E /I /Y "%TEMP_DEPS%\IRremoteESP8266" "%ARDUINO_LIB_PATH%\IRremoteESP8266"
xcopy /E /I /Y "%TEMP_DEPS%\lvgl" "%ARDUINO_LIB_PATH%\lvgl"
xcopy /E /I /Y "%TEMP_DEPS%\RadioLib" "%ARDUINO_LIB_PATH%\RadioLib"
xcopy /E /I /Y "%TEMP_DEPS%\SensorLib" "%ARDUINO_LIB_PATH%\SensorLib"
xcopy /E /I /Y "%TEMP_DEPS%\TFT_eSPI" "%ARDUINO_LIB_PATH%\TFT_eSPI"
xcopy /E /I /Y "%TEMP_DEPS%\TinyGPSPlus" "%ARDUINO_LIB_PATH%\TinyGPSPlus"
xcopy /E /I /Y "%TEMP_DEPS%\XPowersLib" "%ARDUINO_LIB_PATH%\XPowersLib"

echo.
echo ============================================
echo Installazione completata!
echo ============================================
echo.
echo PROSSIMI PASSI:
echo 1. Riavvia Arduino IDE se era aperto
echo 2. Apri: File ^> Examples ^> TTGO_TWatch_Library ^> demo ^> factory
echo 3. Configura Arduino IDE con queste impostazioni:
echo    - Board: ESP32S3 Dev Module
echo    - USB CDC On Boot: Enable
echo    - Flash Size: 16MB (128Mb)
echo    - PSRAM: OPI PSRAM
echo    - Partition Scheme: 16M Flash (3MB APP/9.9MB FATFS)
echo 4. Upload!
echo.
pause
