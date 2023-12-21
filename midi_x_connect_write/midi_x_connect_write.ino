/*
 * midi-x-connect write
 *
 * Created: 21.12.2023
 * Author: Christian Hofschroer
 *
 * This sketch reads ASCII from Serial1 device and writed Binary to MIDI USB
 * 
 * ASCII Data is also logged on USB Serial interface
 *
 */ 

#include "MIDIUSB.h"

byte buffer[4] ;

char readbuffer[256] ;
char incomingByte ;
int i=0 ;


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200) ;
  readbuffer[255]=0 ;
}

void loop() {
  if(i==254) i=0 ;
  
  midiEventPacket_t rx;

  if (Serial1.available() > 0 ) {
  
    // read the incoming byte:
    incomingByte = Serial1.read();
    if(incomingByte==13) incomingByte=0 ;
    if(incomingByte==10) incomingByte=0 ;

    readbuffer[i++]=incomingByte ;
  }

  if(i>8 && i<16 && incomingByte==0) {
      if(sscanf(readbuffer, "%2X %2X %2X %2X", &buffer[0],&buffer[1],&buffer[2],&buffer[3])==4) {
        rx.header=buffer[0] ;
        rx.byte1=buffer[1] ;
        rx.byte2=buffer[2] ;
        rx.byte3=buffer[3] ;

        MidiUSB.sendMIDI(rx) ;
        MidiUSB.flush() ;
 
        Serial.print(rx.header, HEX);
        Serial.print(" ");
        Serial.print(rx.byte1, HEX);
        Serial.print(" ");
        Serial.print(rx.byte2, HEX);
        Serial.print(" ");
        Serial.println(rx.byte3, HEX);
      }

    }
    if(incomingByte==0) i=0 ;
}
