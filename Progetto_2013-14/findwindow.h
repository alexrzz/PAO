#ifndef FINDWINDOW_H
#define FINDWINDOW_H
#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QString>
#include <QLabel>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <string>
#include "container.h"
using std::string;

class FindWindow: public QDialog
{
Q_OBJECT
public:
      FindWindow(Container<Gioiello*>* =0,QWidget *parent =0);
      bool IsEmpty() const;
      int Value() const;
private:
     Container<Gioiello*>* arc;
     QLineEdit* trova;
     QPushButton* ok;
     QPushButton* annulla;
private slots:
     void clickedOk();
};
#endif // FINDWINDOW_H
