/*
 * midi-x-connect read
 *
 * Created: 21.12.2023
 * Author: Christian Hofschroer
 *
 * This sketch reads Binary from MIDI USB and writes ASCII to Serial1 device
 * 
 * ASCII Data is also logged on USB Serial interface
 *
 */ 

#include "MIDIUSB.h"


void setup() {
  Serial.begin(115200);
  Serial1.begin(115200) ;
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {
      Serial1.print(rx.header, HEX);
      Serial1.print(" ");
      Serial1.print(rx.byte1, HEX);
      Serial1.print(" ");
      Serial1.print(rx.byte2, HEX);
      Serial1.print(" ");
      Serial1.println(rx.byte3, HEX);

      Serial.print(rx.header, HEX);
      Serial.print(" ");
      Serial.print(rx.byte1, HEX);
      Serial.print(" ");
      Serial.print(rx.byte2, HEX);
      Serial.print(" ");
      Serial.println(rx.byte3, HEX);

    }

  } while (rx.header != 0);
}
