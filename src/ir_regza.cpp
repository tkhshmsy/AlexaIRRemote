#include "ir_regza.h"

IRRegza::IRRegza(IRsend *irsend)
    :
    irsend(irsend)
{
}

IRRegza::~IRRegza()
{
}

void IRRegza::send(IRRegza::Command command)
{
    uint64_t send = 0;
    switch(command) {
    case IRRegza::Command::Power:
        send = 0x02fd48b7;
        break;
    case IRRegza::Command::InputSelect:
        send = 0x02fdf00f;
        break;
    case IRRegza::Command::TS:
        send = 0x02fd5ea1;
        break;
    case IRRegza::Command::BS:
        send = 0x02fd3ec1;
        break;
    case IRRegza::Command::CS:
        send = 0x02fdbe41;
        break;
    case IRRegza::Command::Channel1:
        send = 0x02fd807f;
        break;
    case IRRegza::Command::Channel2:
        send = 0x02fd40bf;
        break;
    case IRRegza::Command::Channel3:
        send = 0x02fdc03f;
        break;
    case IRRegza::Command::Channel4:
        send = 0x02fd20df;
        break;
    case IRRegza::Command::Channel5:
        send = 0x02fda05f;
        break;
    case IRRegza::Command::Channel6:
        send = 0x02fd609f;
        break;
    case IRRegza::Command::Channel7:
        send = 0x02fde01f;
        break;
    case IRRegza::Command::Channel8:
        send = 0x02fd10ef;
        break;
    case IRRegza::Command::Channel9:
        send = 0x02fd906f;
        break;
    case IRRegza::Command::Channel10:
        send = 0x02fd50af;
        break;
    case IRRegza::Command::Channel11:
        send = 0x02fdd02f;
        break;
    case IRRegza::Command::Channel12:
        send = 0x02fd30cf;
        break;
    case IRRegza::Command::ChannelUp:
        send = 0x02fdd827;
        break;
    case IRRegza::Command::ChannelDown:
        send = 0x02fdf807;
        break;
    case IRRegza::Command::Mute:
        send = 0x02fd08f7;
        break;
    case IRRegza::Command::VolumeUp:
        send = 0x02fd58a7;
        break;
    case IRRegza::Command::VolumeDown:
        send = 0x02fd7887;
        break;
    default:
        return;
    }
    Serial.print("REGZA.send:");
    Serial.println(int(command));
    irsend->sendNEC(send);
}

String IRRegza::toString(IRRegza::Command command)
{
    String result = "Invalid";
    switch(command) {
    case IRRegza::Command::Power:
        result = "Power";
        break;
    case IRRegza::Command::InputSelect:
        result = "InputSelect";
        break;
    case IRRegza::Command::TS:
        result = "TS";
        break;
    case IRRegza::Command::BS:
        result = "BS";
        break;
    case IRRegza::Command::CS:
        result = "CS";
        break;
    case IRRegza::Command::Channel1:
        result = "Channel1";
        break;
    case IRRegza::Command::Channel2:
        result = "Channel2";
        break;
    case IRRegza::Command::Channel3:
        result = "Channel3";
        break;
    case IRRegza::Command::Channel4:
        result = "Channel4";
        break;
    case IRRegza::Command::Channel5:
        result = "Channel5";
        break;
    case IRRegza::Command::Channel6:
        result = "Channel6";
        break;
    case IRRegza::Command::Channel7:
        result = "Channel7";
        break;
    case IRRegza::Command::Channel8:
        result = "Channel8";
        break;
    case IRRegza::Command::Channel9:
        result = "Channel9";
        break;
    case IRRegza::Command::Channel10:
        result = "Channel10";
        break;
    case IRRegza::Command::Channel11:
        result = "Channel11";
        break;
    case IRRegza::Command::Channel12:
        result = "Channel12";
        break;
    case IRRegza::Command::ChannelUp:
        result = "ChannelUp";
        break;
    case IRRegza::Command::ChannelDown:
        result = "ChannelDown";
        break;
    case IRRegza::Command::Mute:
        result = "Mute";
        break;
    case IRRegza::Command::VolumeUp:
        result = "VolumeUp";
        break;
    case IRRegza::Command::VolumeDown:
        result = "VolumeDown";
        break;
    default:
        break;
    }
    return result;
}
