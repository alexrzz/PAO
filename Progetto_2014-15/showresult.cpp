#include "showresult.h"

ShowResult::ShowResult(Utente* u, Utente* z, QWidget *parent) : QDialog(parent), ut(u), p(z)
{
    resize(400,400);
    setModal(true);
    QLabel* label=new QLabel(tr("Utente trovato"));
    nome = new QLabel("");
    cognome = new QLabel("");
    titoloStudio = new QLabel("");
    lingue = new QLabel("");
    espProf = new QLabel("");
    presentazione = new QLabel("");
    contatti = new QPushButton("Mostra contatti");
    contatti->setEnabled(false);
    QFormLayout* formLayout = new QFormLayout;
    formLayout->addRow(tr("&Nome:"), nome);
    formLayout->addRow(tr("&Cognome:"), cognome);
    formLayout->addRow(tr("&TitoloStudio:"), titoloStudio);
    formLayout->addRow(tr("&Lingue:"), lingue);
    formLayout->addRow(tr("&Esp. Prof.:"), espProf);
    formLayout->addRow(tr("&Presentazione:"), presentazione);
    QVBoxLayout* vertical = new QVBoxLayout;
    UtenteBusiness* utb = dynamic_cast<UtenteBusiness*>(ut);
    UtenteExecutive* ute = dynamic_cast<UtenteExecutive*>(ut);
    UtenteBasic* pb = dynamic_cast<UtenteBasic*>(p);
    UtenteBusiness* pbs = dynamic_cast<UtenteBusiness*>(p);
    UtenteExecutive* pe = dynamic_cast<UtenteExecutive*>(p);
    if(utb && !ute) {
        if(pb && !pbs && !pe) {
        nome->setText(QString::fromStdString(pb->getNome()));
        cognome->setText(QString::fromStdString(pb->getCognome()));
        titoloStudio->setText(QString::fromStdString(pb->getTitoloStudio()));
        lingue->setText(QString::fromStdString(pb->getLingue()));
        espProf->setText("");
        presentazione->setText("");
        cont = pb->getContatti();
        }
        else if(pbs && !pe) {
            nome->setText(QString::fromStdString(pbs->getNome()));
            cognome->setText(QString::fromStdString(pbs->getCognome()));
            titoloStudio->setText(QString::fromStdString(pbs->getTitoloStudio()));
            lingue->setText(QString::fromStdString(pbs->getLingue()));
            espProf->setText(QString::fromStdString(pbs->getEspProf()));
            presentazione->setText("");
            cont = pbs->getContatti();
        }
            else {
            nome->setText(QString::fromStdString(pe->getNome()));
            cognome->setText(QString::fromStdString(pe->getCognome()));
            titoloStudio->setText(QString::fromStdString(pe->getTitoloStudio()));
            lingue->setText(QString::fromStdString(pe->getLingue()));
            espProf->setText(QString::fromStdString(pe->getEspProf()));
            presentazione->setText(QString::fromStdString(pe->getPresentazione()));
            cont = pe->getContatti();
        }
    }
    else if(ute) {
        contatti->setEnabled(true);
        if(pb && !pbs && !pe) {
            nome->setText(QString::fromStdString(pb->getNome()));
            cognome->setText(QString::fromStdString(pb->getCognome()));
            titoloStudio->setText(QString::fromStdString(pb->getTitoloStudio()));
            lingue->setText(QString::fromStdString(pb->getLingue()));
            espProf->setText("");
            presentazione->setText("");
            cont = pb->getContatti();
        }
        else if(pbs && !pe) {
            nome->setText(QString::fromStdString(pbs->getNome()));
            cognome->setText(QString::fromStdString(pbs->getCognome()));
            titoloStudio->setText(QString::fromStdString(pbs->getTitoloStudio()));
            lingue->setText(QString::fromStdString(pbs->getLingue()));
            espProf->setText(QString::fromStdString(pbs->getEspProf()));
            presentazione->setText("");
            cont = pbs->getContatti();
        }
            else {
            nome->setText(QString::fromStdString(pe->getNome()));
            cognome->setText(QString::fromStdString(pe->getCognome()));
            titoloStudio->setText(QString::fromStdString(pe->getTitoloStudio()));
            lingue->setText(QString::fromStdString(pe->getLingue()));
            espProf->setText(QString::fromStdString(pe->getEspProf()));
            presentazione->setText(QString::fromStdString(pe->getPresentazione()));
            cont = pe->getContatti();
        }
    }
    vertical->addWidget(label);
    vertical->addLayout(formLayout);
    vertical->addWidget(contatti);
    setLayout(vertical);
    connect(contatti,SIGNAL(clicked()),this,SLOT(contacts()));
}

void ShowResult::contacts() {
    Contacts* gestione = new Contacts(p,&cont);
    gestione->show();
    gestione->readOnly();
}
