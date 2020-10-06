#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  Serial1.begin(1200);
  pinMode(2,OUTPUT);
  digitalWrite(2,HIGH);
}

void loop(){
    int i;
    i = Serial1.read();
    if (i=='A') Keyboard.println("BadUSB Activate attack plan A.");
    if (i=='B') Keyboard.println("BadUSB Activate attack plan B.");    
    if (i=='C') Keyboard.println("BadUSB Activate attack plan C.");
}
