#include "Adafruit_Thermal.h"
#include "SoftwareSerial.h"
#define TX_PIN 6 // Arduino transmit  YELLOW WIRE  labeled RX on printer
#define RX_PIN 5 // Arduino receive   GREEN WIRE   labeled TX on printer

SoftwareSerial mySerial(RX_PIN, TX_PIN); // Declare SoftwareSerial obj first
Adafruit_Thermal printer(&mySerial); 

int a = 0;
int prea = 0;
int buttonState = 0;
int switchState = 0;
String prompt;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(8, INPUT);
  Serial.begin(9600);
  
  
    pinMode(7, OUTPUT); 
    digitalWrite(7, LOW);
  // NOTE: SOME PRINTERS NEED 9600 BAUD instead of 19200, check test page.
 mySerial.begin(9600);  // Initialize SoftwareSerial
  //Serial1.begin(9600); // Use this instead if using hardware serial
  printer.begin();        // Init printer (same regardless of serial type)

//for the switch knob
pinMode(9, INPUT);
pinMode(10, INPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);
digitalWrite(9, 0);
digitalWrite(10, LOW);
digitalWrite(11, LOW);
digitalWrite(12, LOW);
digitalWrite(13, LOW);
}

void loop() {
 if(digitalRead(9) == 1){
  switchState = 2;
}
else if(digitalRead(10) == 1){
  switchState = 1;
}
else if(digitalRead(11) == 1){
  switchState = 3;
}
else if(digitalRead(12) == 1){
  switchState = 4;
}
else if(digitalRead(13) == 1){
  switchState = 5;
}
else{switchState = 0;}

a = digitalRead(8);


//define button when is pressed
if(a == 1 && prea == 0){
  buttonState = 1;
}
else{buttonState = 0;}


  //case1: truth
  if(switchState == 5){
     sendData();
     }

  //case2: dare normal mode
  else if(switchState == 1){
    sendData();
    }
  //case3: dare
  else if(switchState == 2){
    sendData();
    }
  //case4: dare
  else if(switchState == 3){
    sendData();
    }
  //case5: dare  
  else if(switchState == 4){
    sendData();
    }
    

//Serial.println(buttonState);
//Serial.print("switch:");
//Serial.println(switchState);

//Serial.write(buttonState);
prea = a;
}

void sendData(){
  if(buttonState == 1){
   //printer set!!!
      printer.justify('C');
      printer.setFont('A');

      Serial.println(switchState);
      //  printer.println("FontA (default)");
      prompt = Serial.readString();
     
      printer.println(prompt);
//      printer.println("this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence this is a fucking long sentence");
      
      printer.feed(5);
  }
  //if(buttonState == 0){
  //  do nothing
  //}
}
