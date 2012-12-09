#ifndef PLAYERENTITY_H
#define PLAYERENTITY_H

#include "entity.h"
#include "manymouse.h"
#include <QPointF>

class PlayerEntity : public Entity
{
public:
    PlayerEntity();
    static void setupRes(QGLWidget *);

    virtual void processEvent(ManyMouseEvent &);
    virtual void step(float dt);
    virtual void render();

private:
    QPointF pos;
    QPoint cursor;
    QPoint current_target;
    enum {
        IDLING,
        MOVING,
        FOLLOWING_MOUSE
    } state;
    static GLuint image_id;
};

#endif // PLAYERENTITY_H
