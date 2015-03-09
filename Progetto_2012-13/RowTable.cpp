#include "RowTable.h"

RowTable::RowTable(Valori* v,int i,QObject* parent,Squadra* s):QObject(parent),num(i),sq(s),val(v)
{
    nome=new QLineEdit();
    nome->setText("");
    punti=new QSpinBox();
    punti->setValue(0);
    punti->setRange(0,100);
    string sqnome=sq->GetNome();
    int sqpunti=sq->GetPunti();
    nome->setText(QString::fromStdString(sqnome));
    punti->setValue(sqpunti);
    connect(nome,SIGNAL(textChanged(QString)),this,SLOT(ChangeNome(QString)));
    connect(punti,SIGNAL(valueChanged(int)),this,SLOT(ChangePunti(int)));
}

QLineEdit* RowTable::GetNome() const
{
    return nome;
}

QSpinBox* RowTable::GetPunti() const
{
    return punti;
}

Squadra* RowTable::GetSquadra() const
{
    return sq;
}

void RowTable::ChangeNome(QString n)
{
    sq->SetNome(n.toStdString());
    emit Change();
}

void RowTable::ChangePunti(int i)
{
    sq->SetPunti(i);
    emit Change();
}

