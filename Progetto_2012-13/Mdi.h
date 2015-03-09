#ifndef MDI_H
#define MDI_H

#include <QMdiArea>
#include <QScrollArea>
#include <QMessageBox>

#include "Valori.h"
#include "Table.h"
#include "Canvas.h"

class Mdi : public QMdiArea
{
    Q_OBJECT
private:
    QScrollArea* area;
    Valori* val;
    Table* tabella;
    Canvas* view;    
public:
     Mdi(Valori*,QWidget *parent = 0);
public slots:
     void Open();
     void Add();
     void InsVal();
     void Close();
     void Line();
     void Bar();
     void Point();
};

#endif // MDI_H
