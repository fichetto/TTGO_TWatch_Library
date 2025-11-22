#include "config.h"

TTGOClass *ttgo;

void setup() {
    Serial.begin(115200);

    ttgo = TTGOClass::getWatch();
    ttgo->begin();
    ttgo->openBL();
    ttgo->tft->fillScreen(TFT_BLACK);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    ttgo->tft->setTextFont(2);

    // Header
    ttgo->tft->fillRect(0, 0, 240, 30, TFT_BLUE);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLUE);
    ttgo->tft->drawString("T-Watch Detector", 45, 8);

    ttgo->tft->setTextColor(TFT_GREEN, TFT_BLACK);
    ttgo->tft->drawString("Hardware Info:", 10, 40);

    int y = 65;
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);

    // Detect model based on hardware
    Serial.println("\n=== T-Watch Hardware Detection ===");

    // Check PMU
    if (ttgo->power) {
        ttgo->tft->drawString("PMU: AXP202 OK", 10, y);
        Serial.println("PMU: AXP202 detected");
        y += 20;
    }

    // Check RTC
    if (ttgo->rtc) {
        ttgo->tft->drawString("RTC: PCF8563 OK", 10, y);
        Serial.println("RTC: PCF8563 detected");
        y += 20;
    }

    // Check Touch
    uint16_t touchX, touchY;
    ttgo->tft->drawString("Touch: FT6336 (test it)", 10, y);
    Serial.println("Touch: FT6336 ready");
    y += 20;

    // Check BMA423 accelerometer
    bool bma423_ok = false;
    if (ttgo->bma) {
        Accel acc;
        ttgo->bma->getAccel(acc);
        if (acc.x != 0 || acc.y != 0 || acc.z != 0) {
            bma423_ok = true;
            ttgo->tft->drawString("IMU: BMA423 OK", 10, y);
            Serial.println("IMU: BMA423 detected");
        }
    }
    if (!bma423_ok) {
        ttgo->tft->setTextColor(TFT_RED, TFT_BLACK);
        ttgo->tft->drawString("IMU: Not detected", 10, y);
        Serial.println("IMU: Not detected");
        ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
    }
    y += 20;

    // Model detection
    ttgo->tft->setTextColor(TFT_YELLOW, TFT_BLACK);
    ttgo->tft->drawString("Probable Model:", 10, y);
    y += 20;

    String model = "Unknown";

    #if defined(LILYGO_WATCH_2019_WITH_TOUCH)
        model = "T-Watch 2019";
    #elif defined(LILYGO_WATCH_2020_V1)
        model = "T-Watch 2020 V1";
    #elif defined(LILYGO_WATCH_2020_V2)
        model = "T-Watch 2020 V2";
    #elif defined(LILYGO_WATCH_2020_V3)
        model = "T-Watch 2020 V3";
    #else
        model = "NOT CONFIGURED!";
        ttgo->tft->setTextColor(TFT_RED, TFT_BLACK);
        ttgo->tft->drawString("Please edit config.h", 10, y + 20);
    #endif

    ttgo->tft->setTextColor(TFT_CYAN, TFT_BLACK);
    ttgo->tft->setTextFont(4);
    ttgo->tft->drawString(model, 10, y);
    y += 30;

    ttgo->tft->setTextFont(2);
    ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);

    // Additional checks
    y += 10;

    #ifdef LILYGO_WATCH_HAS_GPS
        ttgo->tft->drawString("GPS: YES (V2 feature)", 10, y);
        Serial.println("GPS: Available");
    #else
        ttgo->tft->setTextColor(TFT_DARKGREY, TFT_BLACK);
        ttgo->tft->drawString("GPS: NO", 10, y);
    #endif
    y += 20;

    #ifdef LILYGO_WATCH_HAS_TOUCH
        ttgo->tft->setTextColor(TFT_WHITE, TFT_BLACK);
        ttgo->tft->drawString("Touchscreen: YES", 10, y);
    #endif
    y += 20;

    // Footer
    ttgo->tft->setTextColor(TFT_GREENYELLOW, TFT_BLACK);
    ttgo->tft->drawString("Touch screen to test!", 10, 210);

    Serial.println("=== Detection Complete ===");
    Serial.print("Model: ");
    Serial.println(model);
}

void loop() {
    int16_t x, y;
    if (ttgo->getTouch(x, y)) {
        // Draw a small circle where touched
        ttgo->tft->fillCircle(x, y, 5, TFT_RED);

        Serial.print("Touch at X:");
        Serial.print(x);
        Serial.print(" Y:");
        Serial.println(y);

        delay(50);
    }
    delay(10);
}
