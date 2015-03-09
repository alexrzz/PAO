#include "contacts.h"

Contacts::Contacts(Utente* u,vector<Utente*>* ct, vector<Utente*>* c, QWidget *parent) : QDialog(parent), ut(u), cont(ct), arc(c)
{
    setModal(true);
    resize(600,400);
    QVBoxLayout* layout = new QVBoxLayout();
    contatti = new Table(cont);
    contatti -> NewValC();
    aggiungi = new QPushButton(tr("Aggiungi contatto"));
    rimuovi = new QPushButton(tr("Rimuovi contatto"));
    conta = new QPushButton(tr("Conta"));
    layout->addWidget(contatti);
    layout->addWidget(aggiungi);
    layout->addWidget(rimuovi);
    layout->addWidget(conta);
    setLayout(layout);
    connect(aggiungi,SIGNAL(clicked()),this,SLOT(add()));
    connect(rimuovi,SIGNAL(clicked()),this,SLOT(remove()));
    connect(conta,SIGNAL(clicked()),this,SLOT(count()));
}

void Contacts::add()
{
    int dim = arc->size();
    int i = rand() % dim;
    Utente* u = (*arc)[i];
    cont->push_back(u);
    contatti->AddContact(u);
}

void Contacts::remove()
{
    cont->pop_back();
    contatti->RemoveContact(ut);
}


void Contacts::count() {
    Aiuto* ai = new Aiuto(cont,this);
    ai->show();
}

void Contacts::readOnly() {
    aggiungi->setEnabled(false);
    rimuovi->setEnabled(false);
    conta->setEnabled(false);
}
