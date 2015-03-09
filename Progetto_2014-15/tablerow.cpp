#include "tablerow.h"

TableRow::TableRow(vector<Utente*>* v, int i, QObject * parent, Utente* u):QObject(parent),ut(u),arch(v),num(i)
{
    nome = new QLineEdit();
    nome ->setText("");
    cognome = new QLineEdit();
    cognome ->setText("");
    email = new QLineEdit();
    email ->setText("");
    combo=new QComboBox();
    combo->insertItem(1,"Basic");
    combo->insertItem(2,"Business");
    combo->insertItem(3,"Executive");
    combo->setCurrentIndex(0); //Basic
    titoloStudio = new QLineEdit();
    titoloStudio ->setText("");
    lingue = new QLineEdit();
    lingue ->setText("");
    espProf = new QLineEdit();
    espProf ->setText("");
    presentazione = new QLineEdit();
    presentazione ->setText("");
    titoloStudio -> setEnabled(true);
    lingue -> setEnabled(true);
    espProf -> setEnabled(false);
    presentazione -> setEnabled(false);
    string snome = ut -> getNome();
    string scognome = ut -> getCognome();
    string semail = ut -> getEmail();
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeTipo(int)));
    if(dynamic_cast<UtenteBasic*>(ut) && !dynamic_cast<UtenteBusiness*>(ut) && !dynamic_cast<UtenteExecutive*>(ut))
    {
        UtenteBasic* utb=dynamic_cast<UtenteBasic*>(ut);
        string stitoloStudio = utb ->getTitoloStudio();
        string slingue = utb ->getLingue();
        nome->setText(QString::fromStdString(snome));
        cognome->setText(QString::fromStdString(scognome));
        email->setText(QString::fromStdString(semail));
        combo->setCurrentIndex(0);
        titoloStudio ->setText(QString::fromStdString(stitoloStudio));
        lingue -> setText(QString::fromStdString(slingue));
    }
    else
        if(dynamic_cast<UtenteBusiness*>(ut) && !dynamic_cast<UtenteExecutive*>(ut))
        {
            UtenteBusiness* utbs = dynamic_cast<UtenteBusiness*>(ut);
            string sespProf = utbs->getEspProf();
            string stitoloStudio = utbs ->getTitoloStudio();
            string slingue = utbs ->getLingue();
            nome->setText(QString::fromStdString(snome));
            cognome->setText(QString::fromStdString(scognome));
            email->setText(QString::fromStdString(semail));
            combo->setCurrentIndex(1);
            titoloStudio ->setText(QString::fromStdString(stitoloStudio));
            lingue -> setText(QString::fromStdString(slingue));
            espProf ->setText(QString::fromStdString(sespProf));
        }
        else if(dynamic_cast<UtenteExecutive*>(ut)) {
            UtenteExecutive* ute = dynamic_cast<UtenteExecutive*>(ut);
            string spresentazione = ute->getPresentazione();
            string sespProf = ute->getEspProf();
            string stitoloStudio = ute ->getTitoloStudio();
            string slingue = ute ->getLingue();
            nome->setText(QString::fromStdString(snome));
            cognome->setText(QString::fromStdString(scognome));
            email->setText(QString::fromStdString(semail));
            combo->setCurrentIndex(2);
            titoloStudio ->setText(QString::fromStdString(stitoloStudio));
            lingue -> setText(QString::fromStdString(slingue));
            espProf ->setText(QString::fromStdString(sespProf));
            presentazione ->setText(QString::fromStdString(spresentazione));
        }
    connect(nome,SIGNAL(textChanged(QString)),this,SLOT(ChangeNome(QString)));
    connect(cognome,SIGNAL(textChanged(QString)),this,SLOT(ChangeCognome(QString)));
    connect(email,SIGNAL(textChanged(QString)),this,SLOT(ChangeEmail(QString)));
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeTipoPunt(int)));
    connect(titoloStudio,SIGNAL(textChanged(QString)),this,SLOT(ChangeTitoloStudio(QString)));
    connect(lingue,SIGNAL(textChanged(QString)),this,SLOT(ChangeLingue(QString)));
    connect(espProf,SIGNAL(textChanged(QString)),this,SLOT(ChangeEspProf(QString)));
    connect(presentazione,SIGNAL(textChanged(QString)),this,SLOT(ChangePresentazione(QString)));
}

void TableRow::ReadOnly() {
    nome->setEnabled(false);
    cognome->setEnabled(false);
    email->setEnabled(false);
    combo->setEnabled(false);
    titoloStudio->setEnabled(false);
    lingue->setEnabled(false);
    espProf->setEnabled(false);
    presentazione->setEnabled(false);
}

void TableRow::ChangeTipo(int i) {
    if(i==0)
    {
        titoloStudio -> setEnabled(true);
        lingue -> setEnabled(true);
        espProf -> setEnabled(false);
        presentazione -> setEnabled(false);
        titoloStudio->setText("");
        lingue -> setText("");
        espProf->setText("");
        presentazione ->setText("");
    }
    else
        if(i==1)
        {
            titoloStudio -> setEnabled(true);
            lingue -> setEnabled(true);
            espProf -> setEnabled(true);
            presentazione -> setEnabled(false);
            titoloStudio->setText("");
            lingue -> setText("");
            espProf->setText("");
            presentazione ->setText("");
        }
        else
            if(i==2)
            {
                titoloStudio -> setEnabled(true);
                lingue -> setEnabled(true);
                espProf -> setEnabled(true);
                presentazione -> setEnabled(true);
                titoloStudio->setText("");
                lingue -> setText("");
                espProf->setText("");
                presentazione ->setText("");
            }
}

void TableRow::ChangeTipoPunt(int i) {
    string snome = ut -> getNome();
    string scognome = ut -> getCognome();
    string semail = ut -> getEmail();
    if(i==0) // nuovo tipo UtenteBasic
    {
        delete ut;
        ut = new UtenteBasic(snome,scognome,semail,vector<Utente*>(),"","");
    }
    if(i==1) // nuovo tipo UtenteBusiness
    {
        delete ut;
        ut = new UtenteBusiness(snome,scognome,semail,vector<Utente*>(),"","","");
    }
    if(i==2) // nuovo tipo UtenteExecutive
    {
        delete ut;
        ut = new UtenteExecutive(snome,scognome,semail,vector<Utente*>(),"","","","");
    }
}

QLineEdit* TableRow::GetNome() const
{
    return nome;
}

QLineEdit* TableRow::GetCognome() const
{
    return cognome;
}

QLineEdit* TableRow::GetEmail() const
{
    return email;
}

QComboBox* TableRow::GetTipo() const
{
    return combo;
}

QLineEdit* TableRow::GetTitoloStudio() const
{
    return titoloStudio;
}

QLineEdit* TableRow::GetLingue() const
{
    return lingue;
}

QLineEdit* TableRow::GetEspProf() const
{
    return espProf;
}

QLineEdit* TableRow::GetPresentazione() const
{
    return presentazione;
}

Utente* TableRow::GetUtente() const {
    return ut;
}

void TableRow::ChangeNome(QString n)
{
    ut->setNome(n.toStdString());
}

void TableRow::ChangeCognome(QString cn)
{
    ut->setCognome(cn.toStdString());
}

void TableRow::ChangeEmail(QString e)
{
    ut->setEmail(e.toStdString());
}

void TableRow::ChangeTitoloStudio(QString t)
{
    if(dynamic_cast<UtenteBasic*>(ut))
    {
        UtenteBasic* utb = dynamic_cast<UtenteBasic*>(ut);
        utb->setTitoloStudio(t.toStdString());
    }
}

void TableRow::ChangeLingue(QString l)
{
    if(dynamic_cast<UtenteBasic*>(ut))
    {
        UtenteBasic* utb = dynamic_cast<UtenteBasic*>(ut);
        utb->setLingue(l.toStdString());
    }
}

void TableRow::ChangeEspProf(QString ep)
{
    if(dynamic_cast<UtenteBusiness*>(ut))
    {
        UtenteBusiness* utbs = dynamic_cast<UtenteBusiness*>(ut);
        utbs->setEspProf(ep.toStdString());
    }
}

void TableRow::ChangePresentazione(QString p)
{
    if(dynamic_cast<UtenteExecutive*>(ut))
    {
        UtenteExecutive* ute = dynamic_cast<UtenteExecutive*>(ut);
        ute->setPresentazione(p.toStdString());
    }
}
