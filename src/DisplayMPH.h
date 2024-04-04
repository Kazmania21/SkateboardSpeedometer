#include "Adafruit_GC9A01A.h"
#include "SPI.h"
#include "Adafruit_GFX.h"

class MPHDisplay {
    public:
    Adafruit_GC9A01A* tft;
    
    MPHDisplay(Adafruit_GC9A01A* _tft) {
        tft = _tft;
    }

    void displayMPH(int mph) {
        tft->fillScreen(GC9A01A_BLUE);
        tft->setCursor(100, 90);
        if (mph < 10){
            tft->setCursor(110, 90);
        }
        tft->setTextColor(GC9A01A_WHITE);  
        tft->setTextSize(3);
        tft->println(mph);
        tft->setCursor(90, 120);
        tft->println("MPH");
    }
};
