int ledPin=3;

void on(int num){
    for(int i = 0; i < num; i++) {
      PORTD |= 8;
      delayMicroseconds(9);
      PORTD &= ~8;
      delayMicroseconds(17);
    }
  }
void setup(){
    pinMode(ledPin, OUTPUT); 
    pinMode(4,INPUT_PULLUP);
    pinMode(5,INPUT_PULLUP);
    pinMode(6,INPUT_PULLUP);
  }
void ascii(int c){
  on(32);
  for (int i=0;i<8;i++)
    (c & 1<<i)? delayMicroseconds(26*32):on(32);
  }

  void loop(){
    if (!digitalRead(4)) ascii('A');
    if (!digitalRead(5)) ascii('B');
    if (!digitalRead(6)) ascii('C');
      delay(500);
  }

/*
void ascii(int c){
  on(32);
  (c & 0x01)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x02)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x04)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x08)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x10)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x20)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x40)? delayMicroseconds((17+9)*32):on(32);
  (c & 0x80)? delayMicroseconds((17+9)*32):on(32);
  }
*/

/*  
void loop(){
  on(32);
  //1000-0010 0x41 'A'
  //0111-1101
  delayMicroseconds((17+9)*32); //0
  on(32*5);                      //11111
  delayMicroseconds((17+9)*32); //0
  on(32);                       //1
  delay(200);
  }
*/ 
