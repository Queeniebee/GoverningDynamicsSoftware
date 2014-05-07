// from Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "sides.h"

#define NUMBER_OF_BOXES 4
Servo myservo;  // create servo object to control a servo 
int sliderpin = 0;  // analog pin used to connect the slider
int sliderValue[2]; // 2-item array to act as two boxes; value from the analog pin 
int stack[36];

struct sides {
  int side1;
  int side2;
  int side3;
  int side4;
  int side5;
  int side6;
  
  int weight1;
  int weight2;
  int weight3;
  int weight4;
  int weight5;
  int weight6;

  int function;
} box[NUMBER_OF_BOXES];
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
} 
 
void loop() 
{ 
  for(int i = 0; i < 2; i++){
  sliderValue[i] = analogRead(sliderpin);            // reads the value of the potentiometer (value between 0 and 1023) 
  sliderValue[i] = map(sliderValue[i], 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
  }
  
  //  stackArray[&stack];
//  for(int i = 0; i < 36; i++){
//    stack[i] = box[0]
//  
//  }
  myservo.write(*stack);                  // sets the servo position according to the scaled value 
  delay(15);                            
} 

void sideAssignKeys(){
  for(int i = 0; i < NUMBER_OF_BOXES; i++){
  box[i].side1 = addition(sliderValue[0], sliderValue[1]);
  box[i].side2 = subtraction(sliderValue[0], sliderValue[1]);
  box[i].side3 = increment(sliderValue[0], sliderValue[1]);
  box[i].side4 = decrement(sliderValue[0], sliderValue[1]);
  box[i].side5 = saveState(sliderValue[0], sliderValue[1]);
  box[i].side6 = clearState(sliderValue[0], sliderValue[1]);
  }
  for(int j = 0; j < 6; j++){
  box[j].weight1 = '6';
  box[j].weight2 = '5';
  box[j].weight3 = '4';
  box[j].weight4 = '3';
  box[j].weight5 = '2';
  box[j].weight6 = '1';
  }
}

int addition(int a, int b){ int c = 0; if(a == 0){ return b; } c = a + b; return c; } //1
int subtraction(int a, int b){ int c = 0; if(a >= b){c = a - b;} else {c = b - a;} return c; } //2
int increment(int a, int b){ if(a <= b){ return a + 15; } else return b + 15; } //3
int decrement(int a, int b){ if(a >= b){ return a -15; } else return b - 15;} //4
int saveState(int a, int b){ return a, b; } //5
int clearState(int a, int b){ return b; } //6


int dictionary(int slider[]){
  if(slider[0] > 0){
    if(slider[0] >= 1 && slider[0] < 45){
      //'1'
//      box[0].function = addition();
      return box[0].function;
    }
      
  
  } else return 0;
}

//void stackArray(int *values){
//  int x, y;
//  addition(x, y);
//
//}
