#ifndef TABLE_H
#define TABLE_H

#include <QTableWidget>
#include <QVector>
#include <QStringList>
#include <QMessageBox>
#include <string>
using std::string;

#include "rowTable.h"

class Table : public QTableWidget
{
    Q_OBJECT
private:
   QVector<RowTable*> vec;
   Container<Gioiello*>* arc;
public:
   Table(Container<Gioiello*>* =0,QWidget *parent = 0);
   Gioiello* GetGio(int);
   ~Table();
public slots:
   void Add();
   void InsVal();
   void Remove();
   void InsNew(int);
   void NewVal();
   void DelAll();
};

#endif // TABLE_H
