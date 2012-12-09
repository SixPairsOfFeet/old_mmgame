#ifndef ASSIGNMENTGADGET_H
#define ASSIGNMENTGADGET_H

#include <QWidget>

namespace Ui {
class AssignmentGadget;
}

class AssignmentGadget : public QWidget
{
    Q_OBJECT
    
public:
    explicit AssignmentGadget(QWidget *parent = 0);
    ~AssignmentGadget();
    
private:
    Ui::AssignmentGadget *ui;
};

#endif // ASSIGNMENTGADGET_H
