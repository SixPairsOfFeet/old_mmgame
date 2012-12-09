#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QList>
#include <QPoint>
#include "entity.h"
#include "playerentity.h"

class GameState
{
public:
    GameState();

    void step(float dt);

    QList<PlayerEntity *> players;
    QList<Entity *> entities;

    void spawnEntity(Entity *);
};

#endif // GAMESTATE_H
