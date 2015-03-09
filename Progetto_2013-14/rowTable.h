#ifndef ROWTABLE_H
#define ROWTABLE_H

#include <QObject>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <string>
using std::string;

#include "container.h"

class RowTable : public QObject
{
    Q_OBJECT
private:
    QLineEdit* materiale;
    QSpinBox* qualita;
    QDoubleSpinBox* prezzo;
    QComboBox* combo;
    QDoubleSpinBox* misura;
    QComboBox* solitario;
    QLineEdit* chiusura;
    QComboBox* pendente;
    Gioiello* gio;
    Container<Gioiello*>* arch;
    int num; //numero della riga
public:
     RowTable(Container<Gioiello*>*, int , QObject* =0, Gioiello* = new Anello());
     QLineEdit* GetMateriale() const;
     QSpinBox* GetQualita() const;
     QDoubleSpinBox* GetPrezzo() const;
     QComboBox* GetTipo() const;
     QDoubleSpinBox* GetMisura() const;
     QComboBox* GetSolitario() const;
     QLineEdit* GetChiusura() const;
     QComboBox* GetPendente() const;
     Gioiello* GetGioiello() const;
private slots:
     void ChangeMateriale(QString);
     void ChangeQualita(int);
     void ChangePrezzo(double);
     void ChangeTipo(int);
     void ChangeTipoPunt(int);
     void ChangeMisura(double);
     void ChangeSolitario(int);
     void ChangeChiusura(QString);
     void ChangePendente(int);
};

#endif // ROWTABLE_H
