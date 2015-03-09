#include "login.h"

Login::Login(vector<Utente*>* c, QWidget *parent): QDialog(parent), arc(c) {
    setWindowTitle("Login");
    adjustSize();
    setModal(true);
    QDialog::reject();
    QLabel* label=new QLabel("Inserisci l'email");
    trova= new QLineEdit();
    QHBoxLayout* inputlayout= new QHBoxLayout();
    inputlayout->addWidget(label);
    inputlayout->addWidget(trova);
    ok=new QPushButton(tr("Login!"));
    annulla=new QPushButton(tr("Annulla"));
    ok->setFont(QFont("Helvetica [Cronyx]", 12));
    annulla->setFont(QFont("Helvetica [Cronyx]", 12));
    QDialogButtonBox* button=new QDialogButtonBox(Qt::Horizontal);
    button->addButton(ok,QDialogButtonBox::ActionRole);
    button->addButton(annulla,QDialogButtonBox::ActionRole);
    QVBoxLayout* container=new QVBoxLayout();
    container->addLayout(inputlayout);
    container->addWidget(button);
    setLayout(container);
    connect(ok,SIGNAL(clicked()),this,SLOT(clickedOk()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
}

Utente* Login::search_email(string e) const
{
    Utente* ut = 0;
    vector<Utente*>::const_iterator it = arc->begin();
    for( ; it!=arc->end() ; it++)
        if((*it)->getEmail() == e)
            ut = *it;
    return ut;
}

void Login::clickedOk() {
    if(trova->text()!=""){
        QString tr=trova->text();
        string trst=tr.toStdString();
        if(arc->empty()) QMessageBox::critical(this,"Errore!","DB vuoto!");
        else {
            Utente* p = search_email(trst);
            if(p) { emit loginOk(trst, p); emit noMoreLogin(); close(); }
            else QMessageBox::information(this,"Errore!","E-mail errata!");
        }
    }
    else QMessageBox::critical(this,"Errore!","Inserisci l'e-mail!");
}

