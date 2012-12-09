#ifndef GAMEGLWIDGET_H
#define GAMEGLWIDGET_H

#include "gamestate.h"
#include <QGLWidget>

class GameGLWidget : public QGLWidget
{
    Q_OBJECT
private:
    virtual void paintGL();
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    GameState *state;

    void drawSceneForPlayer(int plid);

public:
    explicit GameGLWidget(QWidget *parent, GameState *state);
    
signals:
    
public slots:
    
};

extern GameGLWidget *active_gglw;
extern int current_player;

#endif // GAMEGLWIDGET_H
