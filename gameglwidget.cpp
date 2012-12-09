#include "gameglwidget.h"

#include <QDebug>
#include "resourcepoint.h"

#include "voronoi.hpp"
#include "voronoi_map.hpp"

GameGLWidget *active_gglw;
QList<bool> active_players;

GLuint detail_thing_texture;
GLuint background_texture;

GameGLWidget::GameGLWidget(QWidget *parent, GameState *state) :
    QGLWidget(parent), state(state)
{

}

void GameGLWidget::renderMap() {
    glEnable(GL_TEXTURE_2D);
    glColor4f(1,1,1,1);
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glScalef(5, 5, 1);
    glMatrixMode(GL_MODELVIEW);

    drawTexture(QRect(0, 0, 800, 600), background_texture, GL_TEXTURE_2D);

    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);

//    glBindTexture(GL_TEXTURE_2D, background_texture);
//    glBegin(GL_QUAD);
//    glVertex2f(0, 0);
//    glVertex2f(800,0);
//    glVertex2f(800,600);

//    glEnd(GL_QUAD);

    srand(100);

    for(int i = 0; i < 1000; i++) {
        QPoint pos(rand()%5000, rand()%5000);
        glColor4f(1,1,1,0.75f + (rand()%1000) / 4000.0f);
        drawTexture(pos - QPoint(32,32), detail_thing_texture, GL_TEXTURE_2D);
    }
    glDisable(GL_TEXTURE_2D);
}

void GameGLWidget::drawSceneForPlayer(QList<bool> players) {
    active_players = players;

    renderMap();

    // draw scene
    foreach (Entity *ent, state->entities) {
        ent->render();
    }

    foreach (PlayerEntity *ent, state->players) {
        ent->render();
    }
}

void GameGLWidget::paintGL() {
    active_gglw = this;
    glClear(GL_COLOR_BUFFER_BIT);

    drawSceneForPlayer(QList<bool>());

    /*if (state->players.size() > 2) {
        srand(100);
        // first, generate a voronoi of our player positions on-screen.
        vector<ivec2> points;

        for (int i = 0; i < 3; i++) {
            points.push_back(ivec2(15+rand()%770, 15+rand()%570));
        }
        foreach (QPoint player, state->players) {
            points.push_back(ivec2(player.x(), player.y()));
            qDebug() << "pushing" << player.x() << player.y();
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
    }*/
}

void GameGLWidget::resizeGL(int w, int h) {
    glViewport(0, 0, (GLint)w, (GLint)h);
    glOrtho(0, 800, 600, 0, -10, 10);
}

void GameGLWidget::initializeGL() {
    ResourcePoint::setupRes(this);
    PlayerEntity::setupRes(this);
    detail_thing_texture = bindTexture(QPixmap(":/res/detailstuff.png"));
    background_texture = bindTexture(QPixmap(":/res/ground.png"));
    qDebug() << detail_thing_texture << background_texture;
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
