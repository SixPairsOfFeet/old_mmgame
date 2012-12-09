#include "playerinput.h"
#include <algorithm>

using std::max;
using std::min;

PlayerInput::PlayerInput(int mm_device, GameState *state, int player_id) :
    mm_device(mm_device), state(state), player_id(player_id)
{
    QPoint pos(400, 300);
}

QPoint PlayerInput::getPos() {
    return QPoint(pos.x(), pos.y());
}

bool PlayerInput::processEvent(ManyMouseEvent &ev) {
    if (ev.device != mm_device) {
        return false;
    }

    state->players[player_id]->processEvent(ev);

    return true;
}
