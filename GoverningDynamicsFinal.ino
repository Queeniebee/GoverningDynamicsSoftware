// from Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "sides.h"

#define NUMBER_OF_BOXES 4
Servo myservo1, myservo2, myservo3,  myservo4;

int sliderpin = 0;  // analog pin used to connect the slider
int sliderValue[2]; // 2-item array to act as two boxes; value from the analog pin
int val1, val2;
int stack[6];

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
} box;

void setup() 
{ 
  myservo1.attach(8);
  myservo2.attach(7);
  myservo3.attach(6);
  myservo4.attach(5);
} 

void loop() 
{ 
  for(int i = 0; i < 2; i++){
    sliderValue[i] = analogRead(sliderpin);            // reads the value of the potentiometer (value between 0 and 1023) 
    sliderValue[i] = map(sliderValue[i], 0, 1023, 0, 179);     // scale it to use it with the servo (value between 0 and 180) 
   val1 = 0; 
   val2 = 0;
    if(val1 != sliderValue[i]){
      val1 = sliderValue[i];
    } else {
        val2 = sliderValue[i];

    }
  }
  sideAssignKeys();
  for(int i = 0; i < 6; i++){
    stack[i]  = dictionary(val1, val2);
  }

  myservo1.write(*stack);  // need to add and remove from this array 
    //delay(15);                            
  myservo2.write(*stack);  //delay(15);                            
  myservo3.write(*stack);  //delay(15);                            
  myservo4.write(*stack);  //delay(15);                            

  delay(15);                            
} 

void sideAssignKeys(){
    box.side1 = addition(val1, val2);
    box.side2 = subtraction(val1, val2);
    box.side3 = increment(val1, val2);
    box.side4 = decrement(val1, val2);
    box.side5 = saveState(val1, val2);
    box.side6 = clearState(val1, val2);
}
//Operations
int addition(int a, int b){ 
  int c = 0; 
  if(a == 0){ 
    return b; 
  } 
  c = a + b; 
  return c; 
} //1
int subtraction(int a, int b){ 
  int c = 0; 
  if(a >= b){
    c = a - b;
  } 
  else {
    c = b - a;
  } 
  return c; 
} //2
int increment(int a, int b){ 
  if(a <= b){ 
    return a + 15; 
  } 
  else return b + 15; 
} //3
int decrement(int a, int b){ 
  if(a >= b){ 
    return a -15; 
  } 
  else return b - 15;
} //4
int saveState(int a, int b){ 
  return b; 
} //5
int clearState(int a, int b){ 
  return b; 
} //6


int dictionary(int slider0, int slider1){
    if(slider0 > 0){
      if((slider0 >= 1 && slider0 < 30) || (slider1 >= 1 && slider1 < 30)){
        box.weight1 = 6;
        return box.side1;
      } 
      else if((slider0 >= 30 && slider0 < 60) || (slider1 >= 30 && slider1 < 60)){
        box.weight2 = 5;
        return box.side2;

      } 
      else if((slider0 >= 60 && slider0 < 90) || (slider1 >= 60 && slider1 < 90)){
        box.weight3 = 4;
        return box.side2;
      } 
      else if((slider0 >= 90 && slider0 < 120) || (slider1 >= 90 && slider1 < 120)){
        box.weight4 = 3;
        return box.side4;
      } 
      else if((slider0 >= 120 && slider0 < 150) || (slider1 >= 120 && slider1 < 150)){
        box.weight5 = 2;
        return box.side5;

      } 
      else if((slider0 >= 150 && slider0 < 180) || (slider1 >= 150 && slider1 < 180)){
        box.weight6 = 1;
        return box.side6;

      } else return 0;
  }
  
}  
