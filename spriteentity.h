#ifndef SPRITEENTITY_H
#define SPRITEENTITY_H

#include "entity.h"
#include "gameglwidget.h"

class SpriteEntity : public Entity
{
public:
    SpriteEntity(QString res_path, QPointF pos);

    virtual void render();
    static void setupRes(QGLWidget *);

    QPointF pos;

protected:
    QString res_path;
    QPointF center_point;
    static GLuint image_id;
};

#endif // SPRITEENTITY_H
