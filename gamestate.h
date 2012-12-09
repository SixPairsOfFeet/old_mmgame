#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QList>
#include <QPoint>
#include "entity.h"

class GameState
{
public:
    GameState();

    void step(float dt);

    QList<QPoint> players;
    QList<Entity *> entities;

    void spawnEntity(Entity *);
};

#endif // GAMESTATE_H
