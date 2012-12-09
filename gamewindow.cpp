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

    state = new GameState();
    gglw = new GameGLWidget(this, state);
    this->setCentralWidget(gglw);
    assgad = new AssignmentGadget(this);
    assgad->hide();

    startTimer(1000 / 60);
}

void GameWindow::timerEvent(QTimerEvent *) {
    // poll some MM events
    ManyMouseEvent ev;
    while (ManyMouse_PollEvent(&ev)) {
        if (!plin.contains(ev.device)) {
            if (ev.type == MANYMOUSE_EVENT_BUTTON) {
                // click to join, i guess.
                qDebug() << "player" << ev.device << ManyMouse_DeviceName(ev.device) << "joined the fun!";
                plin[ev.device] = new PlayerInput(ev.device, state);
            }
        } else {
            plin[ev.device]->processEvent(ev);
        }
    }
    gglw->update(); // forgetting this is ... clever
}

void GameWindow::popupPlayerSelectionDlg()
{
    assgad->show();
}

GameWindow::~GameWindow()
{
    delete ui;
}
