/* IRremoteESP8266: IRsendDemo - demonstrates sending IR codes with IRsend.
 *
 * Version 1.1 January, 2019
 * Based on Ken Shirriff's IrsendDemo Version 0.1 July, 2009,
 * Copyright 2009 Ken Shirriff, http://arcfn.com
 *
 * An IR LED circuit *MUST* be connected to the ESP8266 on a pin
 * as specified by kIrLed below.
 *
 * TL;DR: The IR LED needs to be driven by a transistor for a good result.
 *
 * Suggested circuit:
 *     https://github.com/crankyoldgit/IRremoteESP8266/wiki#ir-sending
 *
 * Common mistakes & tips:
 *   * Don't just connect the IR LED directly to the pin, it won't
 *     have enough current to drive the IR LED effectively.
 *   * Make sure you have the IR LED polarity correct.
 *     See: https://learn.sparkfun.com/tutorials/polarity/diode-and-led-polarity
 *   * Typical digital camera/phones can be used to see if the IR LED is flashed.
 *     Replace the IR LED with a normal LED if you don't have a digital camera
 *     when debugging.
 *   * Avoid using the following pins unless you really know what you are doing:
 *     * Pin 0/D3: Can interfere with the boot/program mode & support circuits.
 *     * Pin 1/TX/TXD0: Any serial transmissions from the ESP8266 will interfere.
 *     * Pin 3/RX/RXD0: Any serial transmissions to the ESP8266 will interfere.
 *   * ESP-01 modules are tricky. We suggest you use a module with more GPIOs
 *     for your first time. e.g. ESP-12 etc.
 */

#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

const uint16_t kIrLed = 4;  // ESP8266 GPIO pin to use. Recommended: 4 (D2).

IRsend irsend(kIrLed);  // Set the GPIO to be used to sending the message.
/*
// Example of data captured by IRrecvDumpV2.ino
uint16_t rawData[67] = {9000, 4500, 650, 550, 650, 1650, 600, 550, 650, 550,
                        600, 1650, 650, 550, 600, 1650, 650, 1650, 650, 1650,
                        600, 550, 650, 1650, 650, 1650, 650, 550, 600, 1650,
                        650, 1650, 650, 550, 650, 550, 650, 1650, 650, 550,
                        650, 550, 650, 550, 600, 550, 650, 550, 650, 550,
                        650, 1650, 600, 550, 650, 1650, 650, 1650, 650, 1650,
                        650, 1650, 650, 1650, 650, 1650, 600};
// Example Samsung A/C state captured from IRrecvDumpV2.ino
uint8_t samsungState[kSamsungAcStateLength] = {
    0x02, 0x92, 0x0F, 0x00, 0x00, 0x00, 0xF0,
    0x01, 0xE2, 0xFE, 0x71, 0x40, 0x11, 0xF0};
*/
void setup() {
  irsend.begin();
#if ESP8266
  Serial.begin(115200, SERIAL_8N1, SERIAL_TX_ONLY);
#else   // ESP8266
  Serial.begin(115200, SERIAL_8N1);
#endif  // ESP8266
}

int loopNumber = 1;

void loop() {
  delay(2000);

  Serial.printf("\nEnviando %dº comando para LIGAR o ar\n\n", loopNumber);

  const uint64_t powerOn = 0xB2BFD0;

  irsend.sendCOOLIX(powerOn);

  delay(10000);

  Serial.printf("\nEnviando %dº comando para DESLIGAR o ar\n\n", loopNumber);

  const uint64_t powerOff = 0xB27BE0;
  irsend.sendCOOLIX(powerOff);


  loopNumber++;

  delay(15000);
}
