#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "manymouse.h"

class PlayerInput
{
public:
    PlayerInput(int mm_device);
    void processEvent(ManyMouseEvent &ev);

private:
    int mm_device;
};

#endif // PLAYERINPUT_H
