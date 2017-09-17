# Simple Blink example

This example shows the minimal use of AsyncBlinker to blink the built-in LED
in an Arduino Uno board.

- [__src__](src) Sources directory
    - [__Main.cpp__](src/Main.cpp) Main program

## Execute

### Arduino IDE

0. Install [Arduino IDE][ARD01].
1. Download the [AsyncBlinker.zip][LIB01] library and import in your Arduino IDE.
2. Restart the Arduino IDE and open the example in menu (File > Examples).
3. Compile and load the example to your board.

### Platformio

0. Install [Platformio Core][PIO01].
1. Execute `pio run -t upload` to load the example to your board.

## Code explanation

This example shows how to:

1. Write a callback function that switches a LED:

    void blink_my_led(bool enable) {
        digitalWrite(PIN_LED, enable ? HIGH : LOW);
    }

2. Declare the AsyncBlinker instance to execute the callback function:

    AsyncBlinker blinker(blink_my_led);

3. Indicate to the AsyncBlinker to start the blinking:

    blinker.start();

4. Execute the non-blocking code in the main loop to blink the led:

    blinker.tickUpdate(elapsed_millis);

## Code notes

### Elapsed time in the Arduino framework

The code also shows how to get the system time and calculate the elapsed milliseconds in the main loop of the Arduino framework:

    static unsigned long last_millis = 0;
    unsigned long now_millis = millis();
    unsigned long elapsed_millis = now_millis - last_millis;
    last_millis = now_millis;

### Default blinking time intervals

This example is using the default blinking behaviour: 

1. 500 ms enable 
2. 500 ms disable
3. start again

Go to example [02\_BlinkingIntervals][EXA02] and learn about blinking
intervals.



[ARD01]: https://www.arduino.cc/en/Main/Software
[LIB01]: https://github.com/Treboada/AsyncBlinker/archive/master.zip
[EXA02]: ../02_BlinkingIntervals
[PIO01]: http://docs.platformio.org/en/latest/installation.html
