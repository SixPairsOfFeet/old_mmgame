#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QHash>
#include "gameglwidget.h"
#include "assignmentgadget.h"
#include "playerinput.h"
#include "gamestate.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GameWindow(QWidget *parent = 0);
    ~GameWindow();

public slots:
    void popupPlayerSelectionDlg();
    void release();

private:
    Ui::GameWindow *ui;
    GameGLWidget *gglw;

    QHash<int, PlayerInput*> plin;
    AssignmentGadget *assgad; // haha, i wrote ass
    GameState *state;

    void timerEvent(QTimerEvent *);

    void mousePressEvent(QMouseEvent *);
};

#endif // GAMEWINDOW_H
