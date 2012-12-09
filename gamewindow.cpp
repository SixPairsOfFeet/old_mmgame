#include "gamewindow.h"
#include "ui_gamewindow.h"

#include "playerentity.h"

#include "manymouse.h"

#include <QTimer>
#include <QDebug>

QTimer ungrabTimer;

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

    connect(&ungrabTimer, SIGNAL(timeout()), this, SLOT(release()));
    ungrabTimer.setSingleShot(true);
    ungrabTimer.setInterval(10000);

    connect(ui->actionAssign_players, SIGNAL(triggered()), this, SLOT(popupPlayerSelectionDlg()));
}

void GameWindow::timerEvent(QTimerEvent *) {
    // poll some MM events
    ManyMouseEvent ev;
    while (ManyMouse_PollEvent(&ev)) {
        if (!plin.contains(ev.device)) {
            if (ev.type == MANYMOUSE_EVENT_BUTTON) {
                // click to join, i guess.
                qDebug() << "player" << ev.device << ManyMouse_DeviceName(ev.device) << "joined the fun!";
                PlayerEntity *ent = new PlayerEntity();
                state->players.append(ent);
                plin[ev.device] = new PlayerInput(ev.device, state, state->players.size()-1);
            }
        } else {
            plin[ev.device]->processEvent(ev);
        }
    }
    state->step(1000 / 60.);
    gglw->step(1000 / 60.);
    gglw->updateGL(); // forgetting this is ... clever
}

void GameWindow::popupPlayerSelectionDlg()
{
    assgad->show();
}

GameWindow::~GameWindow()
{
    releaseMouse();
    delete ui;
}

void GameWindow::release() {
    qDebug() << "releasing the mouse";
    releaseMouse();
    qApp->restoreOverrideCursor();
}

void GameWindow::mousePressEvent(QMouseEvent *) {
    if (mouseGrabber() != this) {
        qDebug() << "grabbing the mouse";
        grabMouse();
        qApp->setOverrideCursor(Qt::BlankCursor);
    }
    ungrabTimer.stop();
    ungrabTimer.start();
}
