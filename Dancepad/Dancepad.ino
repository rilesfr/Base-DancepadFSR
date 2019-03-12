// Sketch for In The Groove play on FSR pad
// You will need an Arduino with access to the keyboard library
// If you need any help or assistance, you can contact me personally @ nidyz#0357 on discord

// This code was written with example code from the Adafruit FSR tutorial
// https://learn.adafruit.com/force-sensitive-resistor-fsr/using-an-fsr

// Libraries
#include <Keyboard.h>

// FSR connection variables
int fsrPinDownArrow = 2;   
int fsrPinUpArrow = 0;
int fsrPinLeftArrow = 3;
int fsrPinRightArrow = 1;

// The reading variables for each arrow
int fsrReadingDownArrow;  
int fsrReadingUpArrow;   
int fsrReadingLeftArrow;  
int fsrReadingRightArrow;  

// The sensitivity at wich arrows activate, change to a lower number for a higher sensitivity
// Note: this sensitivity is NOT linear
int fsrActivateDownArrow = 955; 
int fsrActivateRightArrow = 975; 
int fsrActivateLeftArrow = 980; 
int fsrActivateUpArrow = 920;   

// Keystrokes that the arrows send out
char upArrow = 'i';
char leftArrow = 'j';
char rightArrow = 'l';
char downArrow = 'k';

//setup
void setup(void) 
{   
  Keyboard.begin();
}

//runtime loop
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
    Keyboard.press(upArrow);
 }
 else 
 {
    Keyboard.release(upArrow);
 }

 // if statement that sends the keystroke for the LEFT arrow
 if (fsrReadingLeftArrow > fsrActivateLeftArrow) 
 {
    Keyboard.press(leftArrow);
 }
 else 
 {
    Keyboard.release(leftArrow);
 }

 // if statement that sends the keystroke for the RIGHT arrow
 if (fsrReadingRightArrow > fsrActivateRightArrow) 
 {
    Keyboard.press(rightArrow);
 }
 else 
 {
    Keyboard.release(rightArrow);
 }

 // if statement that sends the keystroke for the DOWN arrow
 if (fsrReadingDownArrow > fsrActivateDownArrow) 
 {
    Keyboard.press(downArrow);
 }
 else 
 {
    Keyboard.release(downArrow);
 }
  
}
