#include "./lib/Adafruit_GC9A01A-main/Adafruit_GC9A01A.h"

class MPHDisplay {
    public:
    Adafruit_GC9A01A tft;
    
    public:
    MPHDisplay(Adafruit_GC9A01A tft) {
        tft = tft;
    }

    void displayMPH(float mph) {
        tft.fillScreen(GC9A01A_BLUE);
        tft.setTextColor(GC9A01A_WHITE);  
        tft.setTextSize(1);
        tft.println(mph);
        tft.println("MPH");
    }
};
