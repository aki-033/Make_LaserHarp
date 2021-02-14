#include "MIDIUSB.h"

const int SW1 = 2;

bool led_state = 0;

bool sw_state_now = 0;
bool sw_state_old = 0;

void setup() {

  pinMode(SW1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, led_state);

}

void loop() {

  if(digitalRead(SW1) != sw_state_old){
    delay(10);
    sw_state_now = digitalRead(SW1);
  }

  if(sw_state_now != sw_state_old){
    noteOn(0, 48, 64 * sw_state_now);
    MidiUSB.flush();
  }
  sw_state_old = sw_state_now;

}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
