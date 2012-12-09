#ifndef GAMEGLWIDGET_H
#define GAMEGLWIDGET_H

#include <QGLWidget>
#include <QList>
#include <QPointF>

class GameState;

class GameGLWidget : public QGLWidget
{
    Q_OBJECT
private:
    virtual void paintGL();
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    GameState *state;

    void drawSceneForPlayer(QList<bool>);
    void renderMap();

    QPointF scroll;

public:
    explicit GameGLWidget(QWidget *parent, GameState *state);
    void step(float dt);
    
signals:
    
public slots:
    
};

extern GameGLWidget *active_gglw;
extern QList<bool> active_players;

#endif // GAMEGLWIDGET_H
