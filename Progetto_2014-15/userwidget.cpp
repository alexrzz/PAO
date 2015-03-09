#include "userwidget.h"

UserWidget::UserWidget(vector<Utente*>* c, QWidget *parent, Utente* ut) : QWidget(parent), arc(c), logged(ut), cont(ut->getContatti()) {
    QHBoxLayout* statusLayout = new QHBoxLayout;
    QLabel* label=new QLabel(tr("Accesso effettuato come:"));
    utLoggato = new QLabel(tr("Login non effettuato"));
    contatti = new QPushButton(tr("Mostra contatti"));
    statusLayout->addWidget(label);
    statusLayout->addWidget(utLoggato);
    statusLayout->addWidget(contatti);
    nome = new QTextEdit("");
    cognome = new QTextEdit("");
    titoloStudio = new QTextEdit("");
    lingue = new QTextEdit("");
    espProf = new QTextEdit("");
    presentazione = new QTextEdit("");
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow(tr("&Nome:"), nome);
    formLayout->addRow(tr("&Cognome:"), cognome);
    formLayout->addRow(tr("&TitoloStudio:"), titoloStudio);
    formLayout->addRow(tr("&Lingue:"), lingue);
    formLayout->addRow(tr("&Esp. Prof.:"), espProf);
    formLayout->addRow(tr("&Presentazione:"), presentazione);
    applica = new QPushButton(tr("Applica modifiche"));
    applica->setEnabled(false);
    contatti->setEnabled(false);
    //QHBoxLayout* horizontal = new QHBoxLayout;
    //horizontal->addWidget(applica);
    //horizontal->addWidget(contatti);
    QVBoxLayout* vertical = new QVBoxLayout;
    vertical->addLayout(statusLayout);
    vertical->addLayout(formLayout);
    vertical->addWidget(applica);
    setLayout(vertical);
    nome->setEnabled(false);
    cognome->setEnabled(false);
    titoloStudio->setEnabled(false);
    lingue->setEnabled(false);
    espProf->setEnabled(false);
    presentazione->setEnabled(false);
    connect(applica,SIGNAL(clicked()),this,SLOT(updateDB()));
    connect(contatti,SIGNAL(clicked()),this,SLOT(contacts()));
}

void UserWidget::contacts()
{
    Contacts* gestione = new Contacts(logged,&cont,arc,this);
    gestione->show();
}

void UserWidget::loggedIn(string s, Utente* p) {
    utLoggato->setText(QString::fromStdString(s));
    UtenteBasic* x = dynamic_cast<UtenteBasic*>(p);
    if(x) logged = x;
    cont = x->getContatti();
    nome->setText(QString::fromStdString(x->getNome()));
    cognome->setText(QString::fromStdString(x->getCognome()));
    titoloStudio->setText(QString::fromStdString(x->getTitoloStudio()));
    lingue->setText(QString::fromStdString(x->getLingue()));
    nome->setEnabled(true);
    cognome->setEnabled(true);
    titoloStudio->setEnabled(true);
    lingue->setEnabled(true);
    UtenteBusiness* q = dynamic_cast<UtenteBusiness*>(p);
    UtenteExecutive* z = dynamic_cast<UtenteExecutive*>(p);
    if(q && !z) {
        logged = q;
        cont = q->getContatti();
        espProf->setEnabled(true);
        espProf->setText(QString::fromStdString(q->getEspProf()));
    }
    else if(z) {
        logged = z;
        cont = z->getContatti();
        espProf->setEnabled(true);
        espProf->setText(QString::fromStdString(z->getEspProf()));
        presentazione->setEnabled(true);
        presentazione->setText(QString::fromStdString(z->getPresentazione()));
    }
    applica->setEnabled(true);
    contatti->setEnabled(true);
}

void UserWidget::updateDB() {
    QString nom = nome->toPlainText();
    QString cog = cognome->toPlainText();
    QString ts = titoloStudio->toPlainText();
    QString lin = lingue->toPlainText();
    QString esp = espProf->toPlainText();
    QString pre = presentazione->toPlainText();
    UtenteBasic* x = dynamic_cast<UtenteBasic*>(logged);
    if(x) {
        x->setNome(nom.toStdString());
        x->setCognome(cog.toStdString());
        x->setLingue(lin.toStdString());
        x->setTitoloStudio(ts.toStdString());
    }
    UtenteBusiness* q = dynamic_cast<UtenteBusiness*>(logged);
    if(q)
        q->setEspProf(esp.toStdString());
    UtenteExecutive* z = dynamic_cast<UtenteExecutive*>(logged);
    if(z)
        z->setPresentazione(pre.toStdString());
    emit DBupdated();
}

Utente* UserWidget::getLogged() const {
    return logged;
}
