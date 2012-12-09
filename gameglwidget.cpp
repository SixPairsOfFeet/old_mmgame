#include "gameglwidget.h"

#include <QDebug>

GameGLWidget::GameGLWidget(QWidget *parent) :
    QGLWidget(parent)
{
}

void GameGLWidget::paintGL() {
    glBegin(GL_QUADS);
    glColor4f(0,0,1,0.5);
    glVertex2f(20, 20);
    glVertex2f(40, 20);
    glVertex2f(40, 40);
    glVertex2f(20, 40);
    glEnd();
}

void GameGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(0, 0, 600, 800, -100, 100);
}

void GameGLWidget::initializeGL() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
