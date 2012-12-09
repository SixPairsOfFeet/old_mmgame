#ifndef GAMEGLWIDGET_H
#define GAMEGLWIDGET_H

#include <QGLWidget>

class GameGLWidget : public QGLWidget
{
    Q_OBJECT
private:
    virtual void paintGL();
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);

public:
    explicit GameGLWidget(QWidget *parent = 0);
    
signals:
    
public slots:
    
};

#endif // GAMEGLWIDGET_H
