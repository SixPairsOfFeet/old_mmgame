#include "playerinput.h"
#include <algorithm>

using std::max;
using std::min;

PlayerInput::PlayerInput(int mm_device, GameState *state) :
    mm_device(mm_device), state(state)
{
    QPoint pos(0, 0);
    state->players.append(pos);
    player_id = state->players.count() - 1;
}

QPoint PlayerInput::getPos() {
    return QPoint(pos.x(), pos.y());
}

bool PlayerInput::processEvent(ManyMouseEvent &ev) {
    if (ev.device != mm_device) {
        return false;
    }

    switch (ev.type) {
        case MANYMOUSE_EVENT_RELMOTION:
            if (ev.item == 0)
                pos += QPoint(ev.value, 0);
            else if (ev.item == 1)
                pos += QPoint(0, ev.value);
            break;
    }

    pos.setX(max(min(800, pos.x()), 0));
    pos.setY(max(min(600, pos.y()), 0));

    state->players[player_id] = pos;

    return true;
}
