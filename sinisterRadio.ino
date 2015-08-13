// JT sinisterRadio
// 2014

// NeoPixels :D
#include <Adafruit_NeoPixel.h>
#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// Leonardo Keyboard magic
// char ctrlKey = KEY_LEFT_GUI;            // Mac
char ctrlKey = KEY_LEFT_CTRL;              // Linux (Windows? fucks.given(0))
const int buttonPin = 4;                   // input pin for pushbutton
int pBState = HIGH;                        // for checking the state of a pushButton


void setup() {
  // NeoPixels
  strip.begin();
  strip.show();                           // Initialize all pixels to 'off'

  // LeoKB
  pinMode(buttonPin, INPUT);              // Make the pushButton pin an input.
  Keyboard.begin();                       // Initialize control over the keyboard.
}

void loop() {
  
  int i = 50;
  for (i; i < 100; i++) {  
  
  // LeoKB
  int BState = digitalRead(buttonPin);    // read the pushbutton:
  
  if ((BState != pBState) && (BState == HIGH)) {           
    // If the button state has changed.
    // and it's currently pressed.


    //omg such a hack 0_0
    Keyboard.print("debian\n");
    delay(100);
    Keyboard.print("debian\n");
    
    delay(1000);


    // Send control-c a message
    Keyboard.press(ctrlKey);
    Keyboard.press('c');
    Keyboard.release('c');
    Keyboard.release(ctrlKey);
    
    // Give it a sec
    // Call the script
    Keyboard.print("python rndmNV.py \n");
  }
  
  pBState = BState; // save the current button state for comparison next time:

  colorWipe(strip.Color(01.00*i, 02.55*i, 0), 1);
  }

} 


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
