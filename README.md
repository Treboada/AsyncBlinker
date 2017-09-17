# AsyncBlinker library

[![Travis status](https://travis-ci.org/Treboada/AsyncBlinker.svg?branch=master)](https://travis-ci.org/Treboada/AsyncBlinker)

__Non-blocking C library to manage blinking devices__ (for example, a LED)
changing the state in ON-OFF time intervals. 

- __Tags__: library, C, C++, blink, LED, non-blocking, asynchronous, threads, delay
- __Downloads__: https://github.com/Treboada/AsyncBlinker/releases
- __Repository__: https://github.com/Treboada/AsyncBlinker

## License

This library is __GPL-3.0__ licensed. See the [LICENSE](LICENSE) file.

## Support

Bugs, feature requests, contributions are welcome: 
[__AsyncBlinker issue tracker__](https://github.com/Treboada/AsyncBlinker/issues).

## Library usage

Examples index:

1. [__SimpleBlink__][EXA01] Minimal use of AsyncBlinker to blink the built-in 
   LED in an _Arduino Uno_ board.
2. [__MorseSignals__][EXA02] -ToDo-

### Define a callback function to switch ON or OFF

You must code the blink action with a function that receives the blink state
as a boolean parameter:

        void blink_my_led(bool enable) {
            digitalWrite(PIN_LED, enable ? HIGH : LOW);
        }

### AsyncBlinker instance

Declare the instance controlling the blinking and initialize with your
callback function:

        AsyncBlinker blinker(blink_my_led);

### Call the non-blocking update

Be sure that your main loop calls to the `tickUpdate()` method of the instance 
to update the blinker status. It is necessary to specify the elapsed
milliseconds from the last call:

        blinker.tickUpdate(elapsed_millis);

See in the [__SimpleBlink__ example][EXA01] how to calculate the elapsed time 
in the mail loop.

### Define blinking intervals

AsyncBlinker manages blinking intervals as __arrays of ON and OFF elements__. 
Each element is the __amount of milliseconds (from 0 to 65535)__ to keep ON 
or OFF:

        // default blink (500ms ON and 500ms OFF):
        uint16_t simple_blink[] = { 500, 500 };

        // fast blink (200ms ON and 200ms OFF):
        uint16_t fast_blink[] = { 200, 200 };

        // peaceful blink (20ms ON and 5s OFF):
        uint16_t background_signal[] = { 20, 5000 };

With 3 or more intervals, the first interval is the milliseconds to keep
ON, second interval is to keep OFF, third one to keep OFF, fourth to keep
ON and so on...

        // Morse 'O' (---) and 'S' (...)
        uint16_t morse_o[] = { 900, 300, 900, 300, 900, 300 };
        uint16_t morse_s[] = { 300, 300, 300, 300, 300, 300 };

Tip: the first element is always to switch 'ON', but you can use 0 ms to 
skip it.

### Set the blinking intervals

Call `setIntervals(const uint16_t* intervals, uint8_t count)` method passing 
the array defining the intervals and the number of elements in the array.

        AsyncBlinker blinker(blink_my_led);
        uint16_t fast_blink[] = { 200, 200 };
        blinker.setIntervals(fast_blink, 2);
        blinker.start();

Tip: use `sizeof()` to get the length of an array in bytes and divide by 2 (the
length in bytes of each *uint16\_t* element) to pass the elements count:

        blinker.setIntervals(fast_blink, sizeof(fast_blink) / 2);

### Limit the cycles

By default it cycles intervals endlessly from the first to the last and
restarting with the first again. You can limit to a number of cycles (1-254):

        AsyncBlinker blinker(blink_my_led);
        blinker.start(5); // blinks 5 times

The default 'endlessly' mode can be specified as:

        AsyncBlinker blinker(blink_my_led);
        blinker.start(AsyncBlinkder::ENDLESSLY); 

### Use sub-intervals

-ToDo-


[EXA01]: examples/01_SimpleBlink
[EXA02]: #


