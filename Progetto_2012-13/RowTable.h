#ifndef ROWTABLE_H
#define ROWTABLE_H

#include <QObject>
#include <QSpinBox>
#include <QLineEdit>
#include <QString>
#include <string>
using std::string;

#include "Valori.h"

class RowTable : public QObject
{
    Q_OBJECT
private:
    QLineEdit* nome;
    QSpinBox* punti;
    Squadra* sq;
    Valori* val;
    int num;
public:
     RowTable(Valori *, int , QObject* =0, Squadra* = new Squadra());
     QLineEdit* GetNome() const;
     QSpinBox* GetPunti() const;
     Squadra* GetSquadra() const;
private slots:
     void ChangeNome(QString);
     void ChangePunti(int);
signals:
     void Change();
};

#endif // ROWTABLE_H
