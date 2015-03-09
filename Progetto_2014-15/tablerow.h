#ifndef TABLEROW_H
#define TABLEROW_H

#include <QObject>
#include <QComboBox>
#include <QLineEdit>
#include <QString>
#include <string>
#include <vector>
#include <QPushButton>
#include "utente.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"

using std::string;
using std::vector;

class TableRow : public QObject
{
    Q_OBJECT
private:
    QLineEdit* nome;
    QLineEdit* cognome;
    QLineEdit* email;
    QComboBox* combo;
    QLineEdit* titoloStudio;
    QLineEdit* lingue;
    QLineEdit* espProf;
    QLineEdit* presentazione;
    //QPushButton* contatti;
    Utente* ut; //puntatore all'utente corrente
    vector<Utente*>* arch; //puntatore al DB
    int num; //numero della riga
public:
    TableRow(vector<Utente*>*, int, QObject * =0, Utente* = new UtenteBasic());
    QLineEdit* GetNome() const;
    QLineEdit* GetCognome() const;
    QLineEdit* GetEmail() const;
    QComboBox* GetTipo() const;
    QLineEdit* GetTitoloStudio() const;
    QLineEdit* GetLingue() const;
    QLineEdit* GetEspProf() const;
    QLineEdit* GetPresentazione() const;
    //QPushButton* GetContatti() const;
    Utente* GetUtente() const;
public slots:
    void ChangeNome(QString);
    void ChangeCognome(QString);
    void ChangeEmail(QString);
    void ChangeTipo(int);
    void ChangeTipoPunt(int);
    void ChangeTitoloStudio(QString);
    void ChangeLingue(QString);
    void ChangeEspProf(QString);
    void ChangePresentazione(QString);
    void ReadOnly();
};

#endif // TABLEROW_H
