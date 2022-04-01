#include <IRremote.h>
#include "Keyboard.h"

int recvPin = 7;
IRrecv irrecv(recvPin);

void  setup ( )
{
  Serial.begin(9600);   
  irrecv.enableIRIn(); 
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Keyboard.begin();
}

void  loop ( )
{
  decode_results  results;       

  if (irrecv.decode(&results)) { 
      Serial.println(results.value, HEX);
      if (results.value==0xFF48B7)
          Keyboard.println("Hello IRBadUSB!");
      irrecv.resume();            
  }
}
