#include "playerentity.h"
#include "gameglwidget.h"
#include <glm/glm.hpp>

#include <algorithm>

#include <QDebug>

using std::min;
using std::max;

PlayerEntity::PlayerEntity()
{
    state = MOVING;
    pos = QPoint(100, 100);
}

GLuint PlayerEntity::image_id;
void PlayerEntity::setupRes(QGLWidget *glw) {
    image_id = glw->bindTexture(QPixmap(":/res/player_vehicle.png"));
}

void PlayerEntity::step(float dt) {
    if (state == MOVING || state == FOLLOWING_MOUSE) {
        QPointF delta = pos - QPointF(current_target);
        glm::vec2 diff = glm::vec2(delta.x(), delta.y());
        if (glm::length(diff) <= 1) {
            state = IDLING;
        } else {
            diff = (diff / glm::length(diff)) * (0.1f * dt);
            pos -= QPointF(diff.x, diff.y);
        }
    }
}

void PlayerEntity::render() {
    glEnable(GL_TEXTURE_2D);

    glColor4f(1,1,1,1);
    active_gglw->drawTexture(pos - QPoint(32,32), image_id, GL_TEXTURE_2D);

    glDisable(GL_TEXTURE_2D);
    glColor4f(1, 0, 0, 1);
    glPushMatrix();
    glTranslatef(cursor.x(), cursor.y(), 0);
    glBegin(GL_LINES);
        glVertex2f(-10, 0);
        glVertex2f(-5,0);
        glVertex2f(10, 0);
        glVertex2f(5,0);
        glVertex2f(0,-10);
        glVertex2f(0,-5);
        glVertex2f(0,10);
        glVertex2f(0,5);
        glEnd();
    glPopMatrix();
}

void PlayerEntity::processEvent(ManyMouseEvent &ev) {
    switch (ev.type) {
        case MANYMOUSE_EVENT_BUTTON:
            if (ev.value) {
                state = FOLLOWING_MOUSE;
                current_target = cursor;
            } else {
                state = MOVING;
            }
            break;
       case MANYMOUSE_EVENT_RELMOTION:
            if (ev.item == 0)
                cursor += QPoint(ev.value, 0);
            else if (ev.item == 1)
                cursor += QPoint(0, ev.value);
            if (state == FOLLOWING_MOUSE) {
                current_target = cursor;
            }
            break;
    }
    // FIXME: constrict to a circle instead.
    QPointF diff = pos - cursor;
    double len_2 = pow(diff.x(), 2) + pow(diff.y(), 2);
    if (len_2 > 600 * 600) {
        diff /= sqrt(len_2);
        diff *= 600;
        cursor = (pos - diff).toPoint();
    }
}
