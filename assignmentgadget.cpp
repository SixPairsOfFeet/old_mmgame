#include "assignmentgadget.h"
#include "ui_assignmentgadget.h"

#include "manymouse.h"

AssignmentGadget::AssignmentGadget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignmentGadget)
{
    ui->setupUi(this);
    updateMice();
}

AssignmentGadget::~AssignmentGadget()
{
    delete ui;
}

void AssignmentGadget::updateMice() {
    int num_mice = ManyMouse_Init();
    ui->deviceTable->clear();
    for (int i = 0; i < num_mice; i++) {
        ui->deviceTable->addItem(ManyMouse_DeviceName(i));
    }
}
