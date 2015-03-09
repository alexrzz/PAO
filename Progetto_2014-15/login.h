#ifndef LOGIN_H
#define LOGIN_H
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

class Login : public QDialog
{
    Q_OBJECT
public:
    Login(vector<Utente*>* =0,QWidget *parent =0);
    Utente* search_email(string) const;
private:
     vector<Utente*>* arc;
     QLineEdit* trova;
     QPushButton* ok;
     QPushButton* annulla;
public slots:
     void clickedOk();
signals:
     void loginOk(string s, Utente* p);
     void noMoreLogin();
};

#endif // LOGIN_H
