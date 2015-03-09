#ifndef SHOWRESULT_H
#define SHOWRESULT_H

#include <QDialog>
#include "utenteexecutive.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include "contacts.h"
#include <QFormLayout>

class ShowResult : public QDialog
{
    Q_OBJECT
private:
    Utente* ut;//l'utente corrente
    Utente* p; //l'utente da visualizzare
    QLabel* nome;
    QLabel* cognome;
    QLabel* email;
    QLabel* titoloStudio;
    QLabel* lingue;
    QLabel* espProf;
    QLabel* presentazione;
    QPushButton* contatti;
    vector<Utente*> cont;
public:
    ShowResult(Utente*, Utente*,QWidget *parent = 0);
private slots:
    void contacts();
};

#endif // SHOWRESULT_H
