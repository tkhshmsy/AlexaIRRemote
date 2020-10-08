#ifndef __IR_REGZA_H__
#define __IR_REGZA_H__

#include <Arduino.h>

#include <IRremoteESP8266.h>
#include <IRsend.h>

class IRRegza
{
public:
    IRRegza(IRsend *irsend);
    ~IRRegza();

    enum class Command {
        Invalid,
        Power,
        InputSelect,
        TS,
        BS,
        CS,
        Channel1,
        Channel2,
        Channel3,
        Channel4,
        Channel5,
        Channel6,
        Channel7,
        Channel8,
        Channel9,
        Channel10,
        Channel11,
        Channel12,
        ChannelUp,
        ChannelDown,
        Mute,
        VolumeUp,
        VolumeDown,
    };

    void send(IRRegza::Command command);
    String toString(IRRegza::Command command);

private:
    IRsend *irsend;
};

#endif //__IR_REGZA_H__