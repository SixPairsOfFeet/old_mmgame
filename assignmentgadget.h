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

public slots:
    void updateMice();

private:
    Ui::AssignmentGadget *ui;
};

#endif // ASSIGNMENTGADGET_H
