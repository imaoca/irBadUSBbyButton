
#include "Keyboard.h"
#define Button5 9

void setup() {
  Keyboard.begin();
  Serial1.begin(1200);
  pinMode(Button5, INPUT_PULLUP);
}

void loop(){
    int i;
    i = Serial1.read();
    if (i=='A') Keyboard.println("BadUSB Activate attack plan A.");
    if (i=='B') Keyboard.println("BadUSB Activate attack plan B.");    
    if (i=='C') Keyboard.println("BadUSB Activate attack plan C.");
}
/*
void loop() {
  if(digitalRead(Button5) == LOW){
    Keyboard.print("Arduino operating time ");
    Keyboard.write(','); //
    Keyboard.print(millis());
    Keyboard.write('\n');
    delay(100);

    while(digitalRead(Button5) == LOW);
  }

  delay(100);
}
*/
