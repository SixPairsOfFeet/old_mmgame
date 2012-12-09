#include "gamestate.h"

#include "resourcepoint.h"

#include <QDebug>

GameState::GameState()
{
    spawnEntity(new ResourcePoint(QPoint(50, 50)));
}

void GameState::spawnEntity(Entity *ent) {
    entities.append(ent);
    /// later: events and quadtrees and shit
}

void GameState::step(float dt) {
    QList<int> delIdxs;
    int accum = 0;
    int index = 0;
    foreach(Entity *ent, entities) {
        if (ent->deathWish) {
            delIdxs.append(index - accum++);
        } else {
            ent->step(dt);
        }
        index++;
    }
    foreach(int idx, delIdxs) {
        qDebug() << "killed an entity";
        entities.removeAt(idx);
    }

    foreach(PlayerEntity *ent, players) {
        ent->step(dt);
    }
}
