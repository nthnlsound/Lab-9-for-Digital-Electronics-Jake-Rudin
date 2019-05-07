#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
int tempo;
int leds[4] = {31, 30, 29, 28}; 
boolean lastButtonState[4] = {LOW, LOW, LOW, LOW};
boolean buttonState[4] = {LOW,LOW,LOW,LOW};
boolean on[4] = {false,false,false,false};
int ledCount = 4;
int switcho1 = 33;
int switcho2 = 32;
unsigned long time0 = 0;
int currentStep = 0;
int currentStep0 = 3;
int buttonPins[4] = {35, 36, 37, 38};
int testButton = 35;
int testLED = 31;
// GUItool: begin automatically generated code
AudioSynthWaveform  waveform1;          //xy=189,164
AudioOutputAnalog        dac1;           //xy=336,163
AudioConnection          patchCord1(waveform1, dac1);
// GUItool: end automatically generated code


void setup() {
  // put your setup code here, to run once:
  AudioMemory(12);
  waveform1.begin(WAVEFORM_SINE);
  waveform1.amplitude(0.1); //amplitude (volume) can be 0 to 1 and this is a good volume for headphones
  
  for (int i = 0; i < ledCount; i ++){
    pinMode(leds[i], OUTPUT);
    pinMode(buttonPins[i], INPUT);
  }
  pinMode(switcho1, INPUT); 
  pinMode(switcho2, INPUT); 
}


void loop() {
if (testButton == HIGH){
  digitalWrite(testLED, HIGH);
}
//boolean switch1 = digitalRead(switcho1);
//boolean switch2 = digitalRead(switcho2);
//frequenforward();
//if (switch1 == HIGH){
// if (switch2 == LOW){
// frequenbackward();
// }
// if (switch2 == HIGH){
//   frequenforward();
// }
//}
}



//void frequenforward(){
//    
//   
//    tempo = analogRead(A15);
//    if (millis() > time0 + tempo){
//      digitalWrite(leds[currentStep], LOW);
//    
//      currentStep = currentStep + 1;
//    if (currentStep > 3) {
//      currentStep = 0;
//    }
//    time0 = millis();
//    digitalWrite(leds[currentStep], HIGH);
//    potvals[currentStep] = analogRead(potpins[currentStep]);
//    mappedpots[currentStep] = map(potvals[currentStep], 0 , 1023, 266 ,522);
//    waveform1.frequency(mappedpots[currentStep]); 
//  }}
//
//  void frequenbackward(){
//    
//   
//    tempo = analogRead(A15);
//    if (millis() > time0 + tempo){
//      digitalWrite(leds[currentStep], LOW);
//    
//      currentStep = currentStep - 1;
//    if (currentStep <0) {
//      currentStep = 3;
//    }
//    time0 = millis();
//    digitalWrite(leds[currentStep], HIGH);
//    potvals[currentStep] = analogRead(potpins[currentStep]);
//    mappedpots[currentStep] = map(potvals[currentStep], 0 , 1023, 266 ,522);
//    waveform1.frequency(mappedpots[currentStep]); 
//  }}
void pushOnPushOff_theLongWay() {
  lastButtonState = buttonState;    
  buttonState = digitalRead(buttonPin);
    if(buttonState[i] == HIGH && lastButtonState[i] == LOW) {
      if(on == false) {
        on = true;
      } else if(on == true) {
        on = false;
      }
    }  
}

//does the same thing as the checkButton() but with much less code
void pushOnPushOff_theShortWay() {
  
  lastButtonState = buttonState;    
  buttonState = digitalRead(buttonPin);
  
    if(buttonState == HIGH && lastButtonState == LOW) {
      on = !on; //the ! means "the opposite".. so if on is
            //true, this sets it to false, if on is false
            //it sets it to true
    }  
}



void setLed() {
  if(on == true) {
      digitalWrite(ledPin, HIGH);
    } else if(on == false) {
        digitalWrite(ledPin, LOW);
    }  
}

void diaperMan(){
  print("DIAPERMAN");
}
}
