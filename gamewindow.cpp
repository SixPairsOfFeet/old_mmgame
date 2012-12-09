#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "manymouse.h"

#include <QTimer>
#include <QDebug>

GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    gglw = new GameGLWidget(this);
    this->setCentralWidget(gglw);
    assgad = new AssignmentGadget(this);
    assgad->hide();

    popupPlayerSelectionDlg();

    startTimer(1000 / 60);
}

void GameWindow::timerEvent(QTimerEvent *) {
    // poll some MM events
    ManyMouseEvent ev;
    while (ManyMouse_PollEvent(&ev)) {
        qDebug() << "MM event from mouse" << ev.device;
    }
}

void GameWindow::popupPlayerSelectionDlg()
{
    assgad->show();
}

GameWindow::~GameWindow()
{
    delete ui;
}
