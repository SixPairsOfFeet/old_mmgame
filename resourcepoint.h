#ifndef RESOURCEPOINT_H
#define RESOURCEPOINT_H

#include "entity.h"
#include <QPoint>
#include <QGLWidget>

class ResourcePoint : public Entity
{
public:
    ResourcePoint(QPoint pos, int resPerTick=50);
    ~ResourcePoint() {}

    int resPerTick;

    virtual void step(float dt);
    virtual void render();
    static void setupRes(QGLWidget *);
private:
    QPoint pos;
    static GLuint image_id;
};

#endif // RESOURCEPOINT_H
