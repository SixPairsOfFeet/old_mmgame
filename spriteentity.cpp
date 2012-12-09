#include "spriteentity.h"

SpriteEntity::SpriteEntity(QString res_path, QPointF pos) :
    res_path(res_path), pos(pos)
{
}

GLuint SpriteEntity::image_id;
void SpriteEntity::setupRes(QGLWidget *glw) {
    QPixmap img = QPixmap(res_path);
    image_id = glw->bindTexture(img);
    center_point = QPointF(img.rect().bottomRight()) / 2;
}

void PlayerEntity::render() {
    glEnable(GL_TEXTURE_2D);

    glColor4f(1,1,1,1);
    active_gglw->drawTexture(pos - center_point, image_id, GL_TEXTURE_2D);
}
