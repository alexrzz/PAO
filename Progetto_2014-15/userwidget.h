#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include <QTextEdit>
#include <QFormLayout>
#include "utenteexecutive.h"
#include "contacts.h"

using std::vector;

class UserWidget : public QWidget
{
    Q_OBJECT
public:
    Utente* getLogged() const;
    UserWidget(vector<Utente*>* =0,QWidget *parent = 0,Utente* = new UtenteBasic());
private:
    vector<Utente*>* arc;
    QLabel* utLoggato;
    Utente* logged; // l'utente che ha fatto il login
    vector<Utente*> cont;
    QTextEdit* nome;
    QTextEdit* cognome;
    QTextEdit* titoloStudio;
    QTextEdit* lingue;
    QTextEdit* espProf;
    QTextEdit* presentazione;
    QPushButton* applica;
    QPushButton* contatti;
public slots:
    void loggedIn(string s, Utente* p);
    void updateDB();
    void contacts();
signals:
    void DBupdated();
};

#endif // USERWIDGET_H
