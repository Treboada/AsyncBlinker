# Simple Blink example

This example shows the minimal code to blink the built-in LED in _Arduino Uno_ 
board.

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

1. Write a __callback function__ that switches a LED:

        void blink_my_led(bool enable) {
            digitalWrite(PIN_LED, enable ? HIGH : LOW);
        }

2. Declare the __AsyncBlinker instance__ to execute the callback function:

        AsyncBlinker blinker(blink_my_led);

3. Indicate to the AsyncBlinker to __start the blinking__:

        blinker.start();

4. Execute the non-blocking __code in the main loop__ to blink the led:

        blinker.tickUpdate(elapsed_millis);

## Code notes

### Another yet blink example?

Yes! But this blink is non-blocking (no delays). You can do more things in the
main loop and the blinking continues.

Of course, you mustn't use another code blocking the execution (delaying) or
the blinker won't update the state...

### Elapsed time in the Arduino framework

The code also shows how to get the system time and calculate the elapsed 
milliseconds in the main loop of the Arduino framework:

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

