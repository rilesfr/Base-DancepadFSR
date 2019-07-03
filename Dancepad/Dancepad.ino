// Sketch for In The Groove play on FSR pad
// You will need an Arduino with access to the keyboard library

// This code was written with example code from the Adafruit FSR tutorial
// https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

// Libraries
#include <Keyboard.h>

// FSR connection variables
// These numbers correlate to the analog inputs on the arduino
int fsrPinDownArrow = 2;   
int fsrPinUpArrow = 0;
int fsrPinLeftArrow = 4;
int fsrPinRightArrow = 1;

// The reading variables for each arrow
int fsrReadingDownArrow;  
int fsrReadingUpArrow;   
int fsrReadingLeftArrow;  
int fsrReadingRightArrow;  

// The sensitivity at wich arrows activate, change to a lower number for a higher sensitivity
int fsrActivateDownArrow = 955;
int fsrActivateRightArrow = 995;
int fsrActivateLeftArrow = 973;
int fsrActivateUpArrow = 920;

// Setup
void setup(void) 
{   
  Keyboard.begin();
}

// Runtime loop
void loop(void) 
{
 //instances of fsrReading
 fsrReadingDownArrow = analogRead(fsrPinDownArrow);
 fsrReadingUpArrow = analogRead(fsrPinUpArrow);
 fsrReadingLeftArrow = analogRead(fsrPinLeftArrow);
 fsrReadingRightArrow = analogRead(fsrPinRightArrow);
 
 // if statement that sends the keystroke for the UP arrow
 if (fsrReadingUpArrow > fsrActivateUpArrow) 
 {
    Keyboard.press(KEY_UP_ARROW);
 }
 // Releases the UP arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingUpArrow < fsrActivateUpArrow - 10)
 {
    Keyboard.release(KEY_UP_ARROW);
 }

 // if statement that sends the keystroke for the LEFT arrow
 if (fsrReadingLeftArrow > fsrActivateLeftArrow) 
 {
    Keyboard.press(KEY_LEFT_ARROW);
 }
 // Releases the LEFT arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingLeftArrow < fsrActivateLeftArrow - 10)
 {
    Keyboard.release(KEY_LEFT_ARROW);
 }

 // if statement that sends the keystroke for the RIGHT arrow
 if (fsrReadingRightArrow > fsrActivateRightArrow) 
 {
    Keyboard.press(KEY_RIGHT_ARROW);
 }
 // Releases the RIGHT arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingRightArrow < fsrActivateRightArrow - 10)
 {
   Keyboard.release(KEY_RIGHT_ARROW);
 }

 // if statement that sends the keystroke for the DOWN arrow
 if (fsrReadingDownArrow > fsrActivateDownArrow) 
 {
   Keyboard.press(KEY_DOWN_ARROW);
 }
 // Releases the DOWN arrow if the sensitivity is smaller than (activation point - 10)
 else if (fsrReadingDownArrow < fsrActivateDownArrow - 10)
 {
   Keyboard.release(KEY_DOWN_ARROW);
 }
}