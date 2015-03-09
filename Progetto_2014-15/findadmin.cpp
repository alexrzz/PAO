#include "findadmin.h"

FindAdmin::FindAdmin(vector<Utente*>* c, QWidget *parent): QDialog(parent), arc(c) {
    setWindowTitle("Cerca un utente");
    adjustSize();
    setModal(true);
    QDialog::reject();
    QLabel* label=new QLabel("Inserisci l'email");
    trova= new QLineEdit();
    QHBoxLayout* inputlayout= new QHBoxLayout();
    inputlayout->addWidget(label);
    inputlayout->addWidget(trova);
    ok=new QPushButton(tr("Cerca!"));
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

bool FindAdmin::search_email(string e) const
{
    bool trovato = false;
    vector<Utente*>::const_iterator it = arc->begin();
    for( ; !trovato && it!=arc->end() ; it++)
        if((*it)->getEmail() == e)
            trovato = true;
    return trovato;
}

void FindAdmin::clickedOk() {
    if(trova->text()!=""){
        QString tr=trova->text();
        string trst=tr.toStdString();
        if(arc->empty()) QMessageBox::critical(this,"Errore!","DB vuoto!");
        else if(search_email(trst)) QMessageBox::information(this,"Trovato!","L'utente e' presente in archivio!");
        else QMessageBox::information(this,"Assente!","L'utente non e' presente in archivio!");
    }
    else QMessageBox::critical(this,"Errore!","Nulla da cercare!");
}
