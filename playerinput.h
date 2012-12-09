#ifndef PLAYERINPUT_H
#define PLAYERINPUT_H

#include "manymouse.h"
#include <QPoint>
#include "gamestate.h"

class PlayerInput
{
public:
    PlayerInput(int mm_device, GameState *state, int player_id);
    bool processEvent(ManyMouseEvent &ev);

    QPoint getPos();

private:
    int mm_device;
    int player_id;
    QPoint pos;
    GameState *state;
};

#endif // PLAYERINPUT_H
