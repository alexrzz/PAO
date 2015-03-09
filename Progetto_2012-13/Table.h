#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include <QVector>
#include <QStringList>
#include <string>
using std::string;

#include "Valori.h"
#include "RowTable.h"

class Table : public QTableWidget
{
    Q_OBJECT
private:
   QVector<RowTable*> vec;
   Valori* val;
public:
   Table(Valori* =0,QWidget *parent = 0);
   Squadra* GetSq(int);
   ~Table();
signals:
   void Changed();
public slots:
   void InsNew(int);
   void NewVal();
   void DelAll();
};

#endif // TABLE_H
