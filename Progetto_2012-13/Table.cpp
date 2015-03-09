#include "Table.h"

Table::Table(Valori* v,QWidget *parent):QTableWidget(parent),val(v)
{
    setColumnCount(2);
    QStringList header;
    header<<"Squadra"<<"Punti";
    setHorizontalHeaderLabels(header);
    setRowCount(0);
}

Squadra* Table::GetSq(int i)
{
    QVector<RowTable*>::const_iterator it=vec.begin()+i;
    return (*it)->GetSquadra();
}

void Table::InsNew(int i)
{
    insertRow(i);
    RowTable* rowEle=new RowTable(val,i,this);
    vec.push_back(rowEle);
    connect(rowEle,SIGNAL(Change()),this,SIGNAL(Changed()));
    setCellWidget(i,0,rowEle->GetNome());
    setCellWidget(i,1,rowEle->GetPunti());
    setCurrentCell(i,0);
}

void Table::NewVal()
{
        DelAll();
        for(int i=0;i<val->Dim();++i)
        {
            insertRow(i);
            RowTable* rowEle=new RowTable(val,i,this,(*val)[i]);
            vec.push_back(rowEle);
            connect(rowEle,SIGNAL(Change()),this,SIGNAL(Changed()));
            setCellWidget(i,0,rowEle->GetNome());
            setCellWidget(i,1,rowEle->GetPunti());
        }
}

void Table::DelAll()
{
    for(int i=rowCount();i>=0;i--)
            QTableWidget::removeRow(i);
    for(QVector<RowTable*>::const_iterator it=vec.begin();it!=vec.end();++it)
            delete *it;
    vec.clear();
}

Table::~Table()
{
    for(QVector<RowTable*>::const_iterator it=vec.begin();it!=vec.end();++it)
        delete *it;
}
