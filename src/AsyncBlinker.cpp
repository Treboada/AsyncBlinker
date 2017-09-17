/** AsyncBlinker.cpp
 *
 * AsyncBlinker implementation.
 *
 * @version 1.0.1
 * @author Rafa Couto <caligari@treboada.net>
 * @license GNU General Public License v3.0
 * @see https://github.com/Treboada/AsyncBlinker
 *
 */

#include "AsyncBlinker.h"


// blinks each second (500ms ON and 500ms OFF):
static const uint16_t _default_blink[2] = { 500, 500 };


AsyncBlinker::AsyncBlinker(Callback cb)
{
    _callback = cb;
    setIntervals(_default_blink, sizeof(_default_blink) / 2);
}



void AsyncBlinker::setIntervals(const uint16_t* intervals, uint8_t count)
{
    _intervals = intervals;
    _count = count;
    _cycles = 0;
}



void AsyncBlinker::start(uint8_t cycles, uint8_t from, uint8_t to)
{
    _cycles = cycles;
    _from = from;
    _to = to;

    _current = _from;
    _past_millis = 0;

    if (_callback && cycles > 0 && _intervals[from] > 0) _callback(true);
}



void AsyncBlinker::stop()
{
    _cycles = 0;
}



bool AsyncBlinker::tickUpdate(uint32_t elapsed_millis)
{
    if (_cycles == 0) return false;

    _past_millis += elapsed_millis;
    while (_past_millis >= _intervals[_current]) {

        _past_millis -= _intervals[_current];

        if (++_current > _to) {
            _current = _from;
            if (_cycles != ENDLESSLY && --_cycles <= 0) return false;
        }

        if (_callback && (_intervals[_current] > 0)) {
            _callback(_current % 2 == 0);
        }
    }

    return true;
}

