#include "resourcepoint.h"

#include <QGLWidget>
#include "gameglwidget.h"

#include <QDebug>

ResourcePoint::ResourcePoint(QPoint pos, int resPerTick) : pos(pos), resPerTick(resPerTick)
{
}

void ResourcePoint::setupRes(QGLWidget *glw) {
    QPixmap foo = QPixmap(":/res/resource.png");
    image_id = glw->bindTexture(foo);
    foo.save("/tmp/foo.png");
}

void ResourcePoint::render() {
    glEnable(GL_TEXTURE_2D);
    glColor4f(1,1,1,1);
    active_gglw->drawTexture(pos - QPoint(32,32), image_id, GL_TEXTURE_2D);
    glDisable(GL_TEXTURE_2D);
}

void ResourcePoint::step(float dt) {}

GLuint ResourcePoint::image_id;
