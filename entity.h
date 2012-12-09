#ifndef ENTITY_H
#define ENTITY_H

#include <QGLWidget>

class Entity
{
public:
    Entity();
    ~Entity() {}

    virtual void step(float dt) {}
    virtual void render() {}
    static void setupRes(QGLWidget *) {}

    bool deathWish;
};

#endif // ENTITY_H
