/** Main.cpp
 *
 * Main program for 'Simple Blink' example.
 *
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/Treboada/AsyncBlinker
 *
 */

#include <Arduino.h>
#include <AsyncBlinker.h>

#define PIN_LED 13


// This is the callback function switching the LED:
void blink_my_led(bool enable) {

    digitalWrite(PIN_LED, enable ? HIGH : LOW);
}

// the AsyncBlinker instance:
AsyncBlinker blinker(blink_my_led);



void setup() {

    // initialize the hardware
    pinMode(PIN_LED, OUTPUT);

    // start the blinker with default interval (500ms ON, 500ms OFF)
    blinker.start();
}



void loop() {

    // system uptime and elapse between loops
    static unsigned long last_millis = 0;
    unsigned long now_millis = millis();
    unsigned long elapsed_millis = now_millis - last_millis;
    last_millis = now_millis;


    // update the blinker (non-blocking)
    blinker.tickUpdate(elapsed_millis);


    // ...
}



