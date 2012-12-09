#include "gameglwidget.h"

#include <QDebug>
#include "resourcepoint.h"

GameGLWidget *active_gglw;

GameGLWidget::GameGLWidget(QWidget *parent, GameState *state) :
    QGLWidget(parent), state(state)
{

}

void GameGLWidget::paintGL() {
    active_gglw = this;
    glClear(GL_COLOR_BUFFER_BIT);

    // draw scene
    foreach (Entity *ent, state->entities) {
        ent->render();
    }

    // draw players
    glDisable(GL_TEXTURE_2D);
    foreach (QPoint player, state->players) {
        glPushMatrix();
        glTranslatef(player.x(), player.y(), 0);
        glBegin(GL_QUADS);
            glColor4f(0,0,1,0.5);
            glVertex2f(-5, -5);
            glVertex2f(-5, 5);
            glVertex2f(5, 5);
            glVertex2f(5, -5);
        glEnd();
        glPopMatrix();
    }
}

void GameGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(0, 800, 600, 0, -10, 10);
}

void GameGLWidget::initializeGL() {
    ResourcePoint::setupRes(this);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
