#include "gameglwidget.h"

#include <QDebug>
#include "resourcepoint.h"

#include "voronoi.hpp"
#include "voronoi_map.hpp"

GameGLWidget *active_gglw;
int current_player;

GameGLWidget::GameGLWidget(QWidget *parent, GameState *state) :
    QGLWidget(parent), state(state)
{

}

void GameGLWidget::drawSceneForPlayer(int plid) {
    current_player = plid;

    // draw scene
    foreach (Entity *ent, state->entities) {
        ent->render();
    }


}

void GameGLWidget::paintGL() {
    active_gglw = this;
    glClear(GL_COLOR_BUFFER_BIT);

    drawSceneForPlayer(0);

    if (true or state->players.size() >= 2) {
        srand(100);
        // first, generate a voronoi of our player positions on-screen.
        vector<ivec2> points;

        //foreach (QPoint player, state->players) {
        //    points.push_back(ivec2(player.x(), player.y()));
        //}
        for (int i = 0; i < 10; i++) {
            points.push_back(ivec2(15+rand()%770, 15+rand()%570));
        }

        Map m(points, 15, 800-15, 15, 600-15);

        // now, draw a voronoi diagram
        glDisable(GL_TEXTURE_2D);
        for (auto &site : m.sites) {
            glColor4f(1, 0, 0, 1);
            glBegin(GL_LINE_LOOP);
            qDebug() << "this site has" << site.verts.size();
            for (auto vec : site.verts) {
                glVertex2f(vec.x, vec.y);
            }
            glEnd();
            glPushMatrix();
            glTranslatef(site.pos.x, site.pos.y, 0);
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
