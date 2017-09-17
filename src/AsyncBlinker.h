/** AsyncBlinker.h
 *
 * AsyncBlinker class.
 *
 * @version 1.0.1
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/Treboada/AsyncBlinker
 *
 */

#ifndef _ASYNC_BLINKER_H
#define _ASYNC_BLINKER_H

#include <stdint.h>

/**
 * This class manages a blinking led (or any switchable device) changing the
 * light in ON-OFF time intervals.
 *
 */
class AsyncBlinker
{
    public:

        static const int ENDLESSLY = UINT8_MAX;

        typedef void (*Callback)(bool enable);

        AsyncBlinker(Callback cb);

        void setIntervals(const uint16_t* intervals, uint8_t count);

        void setCallback(Callback cb) { _callback = cb; }

        void start(uint8_t cycles, uint8_t from, uint8_t to);
        void start(uint8_t cycles) { start(cycles, 0, _count - 1); }
        void start() { start(ENDLESSLY); }

        void stop();
        bool isStopped() { return (_cycles == 0); }

        bool tickUpdate(uint32_t elapsed_millis);

    private:

        const uint16_t* _intervals;
        uint8_t _count;

        Callback _callback;

        uint8_t _from;
        uint8_t _to;
        uint8_t _current;

        uint32_t _past_millis;
        uint8_t _cycles;
};

#endif // _ASYNC_BLINKER_H

