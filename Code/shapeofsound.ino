/*
 * A PCB implementation of (1) Arduino USBMIDI by Blokas
 * combined with (2) capacitive touch sensor from NUS DID Electronics-As-Material class by Clement Zheng
 * By Eugene Ee for NUS EG2606B: Shape of Sound
 */

#include <CapacitiveSensor.h> // add the CapacitiveSensor library
#include <midi_serialization.h> //add USB MIDI library
#include <usbmidi.h>

long capVal = 0;

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2); // 1MOhm resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired

void setup() {
  cs_4_2.set_CS_Timeout_Millis(50); // set a limit to how long the capacitive sensor takes for each reading
  Serial.begin(9600); // begin serial so we can communicate with the Arduino over USB
}

void loop() {
  // Handle USB Communication
  USBMIDI.poll();

  while (USBMIDI.available()) {
    // We must read entire available data, so in case we receive incoming
    // MIDI data, the host wouldn't get stuck.
    u8 b = USBMIDI.read();
  }
  // Read capacitive sensor
  capVal =  cs_4_2.capacitiveSensor(30);
  Serial.println(capVal); // print the capacitive sensor value in a new line in serial
  if(capVal>500){         // need to adjust this number based on size of capacitive element
    //Serial.println("PRESS");
    sendNote(0, 60, 127); //channel, note, velocity
  }
  
  delay(50); // arbitrary delay to limit data to serial port
  USBMIDI.flush();
}


/* Useful Functions */

void sendNote(uint8_t channel, uint8_t note, uint8_t velocity) {
  USBMIDI.write((velocity != 0 ? 0x90 : 0x80) | (channel & 0xf));
  USBMIDI.write(note & 0x7f);
  USBMIDI.write(velocity &0x7f);
}
