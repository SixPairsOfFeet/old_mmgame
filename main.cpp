#include <QApplication>
#include "gamewindow.h"

#include "manymouse.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GameWindow w;
    w.show();

    qDebug() << ManyMouse_Init() << "mice found";
    qDebug() << ManyMouse_DriverName() << "is the MM driver.";

    return a.exec();
}
