#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QList>
#include "gameglwidget.h"
#include "assignmentgadget.h"
#include "playerinput.h"

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

private:
    Ui::GameWindow *ui;
    GameGLWidget *gglw;

    QList<PlayerInput> plin;
    AssignmentGadget *assgad; // haha, i wrote ass

    void timerEvent(QTimerEvent *);
};

#endif // GAMEWINDOW_H
