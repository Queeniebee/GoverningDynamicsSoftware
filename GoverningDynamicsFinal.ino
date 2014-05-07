// from Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "sides.h"

#define NUMBER_OF_BOXES 4
Servo myservo;  // create servo object to control a servo 
int potpin = 0;  // analog pin used to connect the slider
int val;    // variable to read the value from the analog pin 
struct sides {
  int side1;
  int side2;
  int side3;
  int side4;
  int side5;
  int side6;
  
  int initialServoValue;
} box[NUMBER_OF_BOXES];
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  myservo.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 
} 

int sideRead(){
  for(int i = 0; i < NUMBER_OF_BOXES; i++){
  
  }
  return box = 
}
