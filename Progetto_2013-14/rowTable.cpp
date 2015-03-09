#include "rowTable.h"

RowTable::RowTable(Container<Gioiello*>* c,int i,QObject* parent,Gioiello* g):QObject(parent),gio(g),arch(c),num(i)
{
    materiale=new QLineEdit();
    materiale->setText("");
    qualita=new QSpinBox();
    qualita->setValue(0);
    qualita->setRange(0,1000);
    qualita->setAccelerated(true);
    prezzo= new QDoubleSpinBox();
    prezzo->setValue(0.0);
    prezzo->setRange(0.0,3000.0);
    prezzo->setAccelerated(true);
    combo=new QComboBox();
    combo->insertItem(1,"Anello");
    combo->insertItem(2,"Orecchino");
    combo->setCurrentIndex(0);
    misura= new QDoubleSpinBox();
    misura->setValue(0.0);
    misura->setRange(0.0,30.0);
    misura->setAccelerated(true);
    solitario=new QComboBox();
    solitario->insertItem(1,"Assente");
    solitario->insertItem(2,"Presente");
    solitario->setCurrentIndex(0);
    chiusura=new QLineEdit();
    chiusura->setText("");
    pendente=new QComboBox();
    pendente->insertItem(1,"Assente");
    pendente->insertItem(2,"Presente");
    pendente->setCurrentIndex(0);
    misura->setEnabled(true);
    solitario->setEnabled(true);
    chiusura->setEnabled(false);
    pendente->setEnabled(false);
    string smateriale=gio->getMateriale();
    int squalita=gio->getQualita();
    double prez=gio->getPrezzo();
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeTipo(int)));
    if(dynamic_cast<Anello*>(gio) && !dynamic_cast<Orecchino*>(gio))
    {
        Anello* anello=dynamic_cast<Anello*>(gio);
        double mis=anello->getMisura();
        int sol=anello->getSolitario();
        materiale->setText(QString::fromStdString(smateriale));
        qualita->setValue(squalita);
        prezzo->setValue(prez);
        combo->setCurrentIndex(0);
        misura->setValue(mis);
        solitario->setCurrentIndex(sol);
    }
    else
        if(dynamic_cast<Orecchino*>(gio))
        {
            Orecchino* orecchino=dynamic_cast<Orecchino*>(gio);
            string schiusura=orecchino->getChiusura();
            int pend=orecchino->getPendente();
            materiale->setText(QString::fromStdString(smateriale));
            qualita->setValue(squalita);
            prezzo->setValue(prez);
            combo->setCurrentIndex(1);
            chiusura->setText(QString::fromStdString(schiusura));
            pendente->setCurrentIndex(pend);
        }
    connect(materiale,SIGNAL(textChanged(QString)),this,SLOT(ChangeMateriale(QString)));
    connect(qualita,SIGNAL(valueChanged(int)),this,SLOT(ChangeQualita(int)));
    connect(prezzo,SIGNAL(valueChanged(double)),this,SLOT(ChangePrezzo(double)));
    connect(combo,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeTipoPunt(int)));
    connect(misura,SIGNAL(valueChanged(double)),this,SLOT(ChangeMisura(double)));
    connect(solitario,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangeSolitario(int)));
    connect(chiusura,SIGNAL(textChanged(QString)),this,SLOT(ChangeChiusura(QString)));
    connect(pendente,SIGNAL(currentIndexChanged(int)),this,SLOT(ChangePendente(int)));
}

void RowTable::ChangeTipo(int i){
    if(i==0)
    {
        misura->setEnabled(true);
        solitario->setEnabled(true);
        chiusura->setEnabled(false);
        pendente->setEnabled(false);
        misura->setValue(0.0);
        solitario->setCurrentIndex(0);
        chiusura->setText("");
        pendente->setCurrentIndex(-1);
    }
    else
        if(i==1)
        {
            misura->setEnabled(false);
            solitario->setEnabled(false);
            chiusura->setEnabled(true);
            pendente->setEnabled(true);
            misura->setValue(0.0);
            solitario->setCurrentIndex(-1);
            chiusura->setText("");
            pendente->setCurrentIndex(0);
        }
}

void RowTable::ChangeTipoPunt(int i){
    string smateriale=gio->getMateriale();
    int squalita=gio->getQualita();
    double prez=gio->getPrezzo();
    if(i==0) //è cambiato da orecchino ad anello
    {
        Orecchino* p=dynamic_cast<Orecchino*>(gio);
        string schiusura=p->getChiusura();
        bool spendente=p->getPendente();
        //mi salvo il vecchio valore e lo passo a modify insieme al nuovo
        Gioiello* old = new Orecchino(smateriale,squalita,prez,schiusura,spendente);
        gio=new Anello(smateriale,squalita,prez,0.0,false);
        if(num<arch->size())
            arch->modify(old,gio);
    }
    else
        if(i==1) //è cambiato da anello ad orecchino
        {
            Anello* p=dynamic_cast<Anello*>(gio);
            double smisura=p->getMisura();
            bool ssolitario=p->getSolitario();
            //mi salvo il vecchio valore e lo passo a modify insieme al nuovo
            Gioiello* old = new Anello(smateriale,squalita,prez,smisura,ssolitario);
            gio=new Orecchino(smateriale,squalita,prez,"",false);
            if(num<arch->size())
                arch->modify(old,gio);
        }
}

QLineEdit* RowTable::GetMateriale() const
{
    return materiale;
}

QSpinBox* RowTable::GetQualita() const
{
    return qualita;
}

QDoubleSpinBox* RowTable::GetPrezzo() const
{
    return prezzo;
}

QComboBox* RowTable::GetTipo() const
{
    return combo;
}

QDoubleSpinBox* RowTable::GetMisura() const {
    return misura;
}
QComboBox* RowTable::GetSolitario() const {
    return solitario;
}
QLineEdit* RowTable::GetChiusura() const {
    return chiusura;
}
QComboBox* RowTable::GetPendente() const {
    return pendente;
}
Gioiello* RowTable::GetGioiello() const {
    return gio;
}

void RowTable::ChangeMateriale(QString mt)
{
    gio->setMateriale(mt.toStdString());
}

void RowTable::ChangeQualita(int q)
{
    gio->setQualita(q);
}

void RowTable::ChangePrezzo(double p) {
    gio->setPrezzo(p);
}

void RowTable::ChangeMisura(double m) {
    if(dynamic_cast<Anello*>(gio))
    {
        Anello* anello=dynamic_cast<Anello*>(gio);
        anello->setMisura(m);
    }
}

void RowTable::ChangeSolitario(int s) {
    if(dynamic_cast<Anello*>(gio))
    {
        Anello* anello=dynamic_cast<Anello*>(gio);
        anello->setSolitario(s);
    }
}

void RowTable::ChangeChiusura(QString ch) {
    if(dynamic_cast<Orecchino*>(gio))
    {
        Orecchino* orecchino=dynamic_cast<Orecchino*>(gio);
        orecchino->setChiusura(ch.toStdString());
    }
}

void RowTable::ChangePendente(int p) {
    if(dynamic_cast<Orecchino*>(gio))
    {
        Orecchino* orecchino=dynamic_cast<Orecchino*>(gio);
        orecchino->setPendente(p);
    }
}
