// from Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include "sides.h"

#define NUMBER_OF_BOXES 4
Servo myservo1, myservo2, myservo3,  myservo4;

int sliderpin = 0;  // analog pin used to connect the slider
int sliderValue[2]; // 2-item array to act as two boxes; value from the analog pin
int tofunction1, tofunction2;
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
  }
  sideAssignKeys();
  for(int i = 0; i < 36; i++){
    stack[i]  = dictionary(sliderValue);
  }

  myservo1.write(*stack);  // need to add and remove from this array 
    //delay(15);                            
  myservo2.write(*stack);  //delay(15);                            
  myservo3.write(*stack);  //delay(15);                            
  myservo4.write(*stack);  //delay(15);                            

  delay(15);                            
} 

void sideAssignKeys(){
    box.side1 = addition(sliderValue[0], sliderValue[1]);
    box.side2 = subtraction(sliderValue[0], sliderValue[1]);
    box.side3 = increment(sliderValue[0], sliderValue[1]);
    box.side4 = decrement(sliderValue[0], sliderValue[1]);
    box.side5 = saveState(sliderValue[0], sliderValue[1]);
    box.side6 = clearState(sliderValue[0], sliderValue[1]);
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


int dictionary(int slider[]){
    if(slider[0] > 0){
      if((slider[0] >= 1 && slider[0] < 30) || (slider[1] >= 1 && slider[1] < 30)){
        box.weight1 = 6;
        return box.side1;
      } 
      else if((slider[0] >= 30 && slider[0] < 60) || (slider[1] >= 30 && slider[1] < 60)){
        box.weight2 = 5;
        return box.side2;

      } 
      else if((slider[0] >= 60 && slider[0] < 90) || (slider[1] >= 60 && slider[1] < 90)){
        box.weight3 = 4;
        return box.side2;
      } 
      else if((slider[0] >= 90 && slider[0] < 120) || (slider[1] >= 90 && slider[1] < 120)){
        box.weight4 = 3;
        return box.side4;
      } 
      else if((slider[0] >= 120 && slider[0] < 150) || (slider[1] >= 120 && slider[1] < 150)){
        box.weight5 = 2;
        return box.side5;

      } 
      else if((slider[0] >= 150 && slider[0] < 180) || (slider[1] >= 150 && slider[1] < 180)){
        box.weight6 = 1;
        return box.side6;

      } else return 0;
  }
  
}  
