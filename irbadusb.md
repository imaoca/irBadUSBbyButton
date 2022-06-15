---
marp: true

---

# IR(Infrared) BadUSB attack 

Michihiro Imaoka

---
## Bio
![bg 100% left:50%](face.jpg)
Michihiro Imaoka is a founder of Imaoca Engineering Office in Japan. He is also a FPGA developer, an embedded system developer, and a technical writer. He has been a Microsoft MVP since 2014 (Windows development), Black Hat USA Arsenal presenter in 2020 and 2021.

---
## Introduction

This lecture reports a new risk that becomes from the addition of an IR receiver element to the traditional BadUSB.

IR-BadUSB is operated using an IR remote controller for general household. So, the target and the attacker must be within IR range of the IR remote controller.

Suggests the possibility of an attack from outside the target's office when combined with a WiFi smart device.

---


## IR-BadUSB attack diagram
![](iroverview.jpg)
The attacker operates the IR-BadUSB from a distance by the IR  remote controller. The microcontroller, which is recognized as the HID, then sends the attacker's intended key sequence to the target PC.

---
### Infrared Receiver VS1838B
![bg 100% left:50%](irReceiver.jpg)
When this device is connected to a microcontroller that operates BadUSB, it becomes IR-BadUSB.

- Working Voltage is  2.7V to 5.5V.
- Reception Angle is ± 35 Degree.
- Carrier frequency is 38KHz.
- From the left pin, the order is Signal, GND, and VCC.


---
### IR remote controller
![bg 100% left:50%](irRemocon.jpg)


It is ordinary home remote control device.Infrared rays with wavelengths between 940 nm and 950 nm are used in remote control devices for home use. This controller sends out infrared ray according to the "NEC Infraed Transmission Protocol".

---

### NEC Infrared Transmission Protocol

This protocol is one of the most popular methods of infrared remote control. Infrared wavelength of 950nm is used. It uses 38 KHz as a subcarrier. 32 bits are transferred in one frame. 1 frame transfer time is 67.5 ms.

---

## Arduino pro micro
![bg 100% left:50%](proMicro.jpg)


This is the microcontroller module used in this experiment, which operates as IR-BadUSB when connected to a PC via USB. The microcontroller(ATMega 32U4) has a built-in USB function and operates as a HID (Human Interface Device ) such as a PC keyboard. The program is developed using ArduinoIDE.

---


## source code setup()

~~~
#include <IRremote.h>
#include "Keyboard.h"
int recvPin = 7;
IRrecv irrecv(recvPin);
void  setup ( )
{
  irrecv.enableIRIn(); 
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  digitalWrite(9,HIGH);
  Keyboard.begin();
}
~~~
Use IRremote and Keyboard libraries.
IRremote is a library that codes infrared signals, and Keyboard is a library that allows this microcontroller to act as a PC keyboard.
The setup function is executed only once at startup.Set GPIO to provide positive voltage and ground to the IR receiver signal pins and the IR receiver VCC and GND pins.

---
## source code loop()

~~~
void  loop ( )
{
  decode_results  results;       

  if (irrecv.decode(&results)) { 
      if (results.value==0xFF48B7)
          Keyboard.println("Hello IRBadUSB! #0");
      if (results.value==0xFF906F)
          Keyboard.println("Hello IRBadUSB! #1");
      irrecv.resume();            
  }
}
~~~
The loop( ) function is looping after the Setup function is executed. When the IR receiver receives 0xFF48B7, it sends the key sequence "Hello IRBadUSB! #0" to PC as keyboard.If 0xFF906F is received, the key sequence is "Hello IRBadUSB! #1". They are  the 0 and 1 keys on the IR remote controller.

---


## Digispark Attiny 85
![bg 100% left:50%](digiSpark.jpg)
An even smaller microcontroller (Attiny85), as shown in the photo, could be used to integrate it into a USB dongle. It can be shaped like a USB memory stick.
Also "Leonardo USB ATMEGA32U4 mini development board", like Digispark, is also small and can be directly inserted into a PC's USB port, so it can be integrated into a dongle.

---

## WiFi Smart Device
![bg 100% left:50%](wifi.jpg)
This device bridges WiFi and IR communications. The photo shows its interior. ESP32 is used as the processor.
Placing a this device as AP mode in the target office become a risk to remote control of the IR-BadUSB from outside the office, such as from a mobile device.

---
## LED Lights
![bg 100% left:50%](irLight.jpg)

We have tried infrared camera lights to extend the reach of the infrared ray.

- 48 IR LEDs
- Use with night vision camera
- IR LED Wavelength: 940nm
- Visual range: 5-10 meters
- Adapter power supply: DC 12 V

---
## schematic of an experiments on IR reach with the IR light


![](irLightExp.jpg)


---

## LPWA (Low Power, Wide Area)

We have been talking about IR-BadUSB, and now we would like to talk about a further risk . That is the risk when Badusb and LPWA work together. This is LPWA module. The transfer rate is slow, but the reach is several kilometers or more.

![](LPWA.jpg)


---
## LPWA attack diagram

![](LPWAattack.jpg)

attiny 85 as HID.

---

## components on the target side

![bg 100% left:50%](lpwaRec.jpg)

- USB connector
- Attiny 85 as HID
- LAPW modem

This component connects to the target PC via USB. The target PC is recognized as HID. It behaves as a keyboard on the target PC.


---

## components on the attack side

![bg 100% left:50%](lpwaSend.jpg)
- LPWA Modem
- UART2USB

The attacker connects it to his PC, which is perceived by the PC as a virtual serial port. The attacker manipulates the LPWA modem with AT commands.


---
## Conclusion
- We reported on the new risks posed by BadUSB and IR receivers working together.
- The IR-BadUSB realization method was explained.
- Suggested that combining BadUSB and LPWA is more risky than IR-BadUSB.

---

# Thank you
