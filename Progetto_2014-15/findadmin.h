#ifndef FINDADMIN_H
#define FINDADMIN_H
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
#include <vector>
#include "tab.h"

using std::vector;
using std::string;

class FindAdmin: public QDialog
{
Q_OBJECT
public:
     FindAdmin(vector<Utente*>* =0,QWidget *parent =0);
     bool search_email(string) const;
private:
     vector<Utente*>* arc;
     QLineEdit* trova;
     QPushButton* ok;
     QPushButton* annulla;
private slots:
     void clickedOk();
};
#endif // FINDADMIN_H
