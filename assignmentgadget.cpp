#include "assignmentgadget.h"
#include "ui_assignmentgadget.h"

AssignmentGadget::AssignmentGadget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AssignmentGadget)
{
    ui->setupUi(this);
}

AssignmentGadget::~AssignmentGadget()
{
    delete ui;
}
