#ifndef FINDCLIENT_H
#define FINDCLIENT_H

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
#include "utenteexecutive.h"

using std::vector;
using std::string;

class FindClient: public QDialog
{
Q_OBJECT
public:
     FindClient(Utente* u, vector<Utente*>* =0,QWidget *parent =0);
     Utente* search_email(string) const;
private:
     vector<Utente*>* arc;
     Utente* ut;
     QLineEdit* trova;
     QPushButton* ok;
     QPushButton* annulla;
private slots:
     void clickedOk();
signals:
     void searchOk(Utente* p);
};

#endif // FINDCLIENT_H
