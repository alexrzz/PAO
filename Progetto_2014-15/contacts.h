#ifndef CONTACTS_H
#define CONTACTS_H

#include <QDialog>
#include "utenteexecutive.h"
#include "table.h"
#include <stdlib.h>
#include <QVBoxLayout>
#include <QPushButton>
#include "aiuto.h"
#include "findclient.h"
#include "showresult.h"

class Contacts : public QDialog
{
    Q_OBJECT
private:
    Utente* ut;//l'utente corrente
    vector<Utente*>* cont; //i contatti di ut
    vector<Utente*>* arc;
    Table* contatti; //la tabella per visualizzare i contatti
    QPushButton* aggiungi;
    QPushButton* rimuovi;
    QPushButton* conta;
public:
    Contacts(Utente* p,vector<Utente*>* = 0, vector<Utente*>* =0,QWidget *parent = 0);
public slots:
    void remove();
    void add();
    void count();
    void readOnly();
};

#endif // CONTACTS_H
