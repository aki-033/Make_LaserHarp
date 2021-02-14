#include "MIDIUSB.h"

const int SW1 = 2;

const int sensor = A0;
const int sensor_th = 600;

bool sensor_state_now = 0;
bool sensor_state_old = 0;

void setup() {

  pinMode(SW1, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

  if(analogRead(sensor) < sensor_th){
    // ON
    sensor_state_now = 1;
  }
  else {
    // OFF
    sensor_state_now = 0;
  }

  if(sensor_state_now != sensor_state_old){
    noteOn(0, 48, 64 * sensor_state_now);
    MidiUSB.flush();
  }
  sensor_state_old = sensor_state_now;

}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}
