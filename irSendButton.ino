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

