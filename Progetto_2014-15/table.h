#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include <QVector>
#include <QStringList>
#include <QMessageBox>
#include <QtGui>
#include <QHeaderView>
#include <vector>
#include <string>
#include "tablerow.h"

using std::vector;
using std::string;

class Table : public QTableWidget
{
    Q_OBJECT
public:
    Table(vector<Utente*>* =0,QWidget *parent = 0);
    Utente* GetUt(int);
    ~Table();
 public slots:
    void Add();
    void InsVal();
    void Remove();
    void InsNew(int);
    void NewVal();
    void NewValC();
    void DelAll();
    void DelRecords();
    void RemoveContact(Utente*);
    void AddContact(Utente*);
private:
    QVector<TableRow*> vec;
    vector<Utente*>* arc;
};

#endif // TABLE_H
