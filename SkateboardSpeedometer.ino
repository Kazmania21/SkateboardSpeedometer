#include "src/lib/Adafruit_GC9A01A-main/Adafruit_GC9A01A.h"
#include "src/TicksToRPM.h"
#include "src/RPMToMPH.h"
#include "src/DisplayMPH.h"

// Define pins for display interface. You'll probably need to edit this for
// your own needs:

#if defined(ARDUINO_SEEED_XIAO_RP2040)

  // Pinout when using Seed Round Display for XIAO in combination with
  // Seeed XIAO RP2040. Other (non-RP2040) XIAO boards, any Adafruit Qt Py
  // boards, and other GC9A01A display breakouts will require different pins.
  #define TFT_CS D1 // Chip select
  #define TFT_DC D3 // Data/command
  #define TFT_BL D6 // Backlight control

#else // ALL OTHER BOARDS - EDIT AS NEEDED

// Other RP2040-based boards might not have "D" pin defines as shown above
// and will use GPIO bit numbers. On non-RP2040 boards, you can usually use
// pin numbers silkscreened on the board.
  #define TFT_DC  9
  #define TFT_CS 10
// If display breakout has a backlight control pin, that can be defined here
// as TFT_BL. On some breakouts it's not needed, backlight is always on.

#endif

const float RADIUS = .2; //in feet

Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
TicksToRPMConverter ticksToRPMConverter;
RPMToMPHConverter rpmToMPHConverter(RADIUS);
MPHDisplay mphDisplay(tft);

void setup() {
  // put your setup code here, to run once:
  tft.begin();
  #if defined(TFT_BL)
    pinMode(TFT_BL, OUTPUT);
    digitalWrite(TFT_BL, HIGH); // Backlight on
  #endif // end TFT_BL
}

void loop() {
  // put your main code here, to run repeatedly:
  float rpm = ticksToRPMConverter.READ_RPM();
  float mph = rpmToMPHConverter.Convert(rpm);
  mphDisplay.displayMPH(mph);
}
