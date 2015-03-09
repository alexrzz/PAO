#include "table.h"

Table::Table(Container<Gioiello*>* c,QWidget *parent):QTableWidget(parent), arc(c)
{
    setColumnCount(8);
    QStringList header;
    header<<"Materiale"<<"Qualita'"<<"Prezzo"<<"Tipo"<<"Misura"<<"Solitario"<<"Chiusura"<<"Pendente";
    setHorizontalHeaderLabels(header);
    setRowCount(0);
}

Gioiello* Table::GetGio(int i)
{
    QVector<RowTable*>::const_iterator it=vec.begin()+i;
    return (*it)->GetGioiello();
}

void Table::Remove()
{
    if(rowCount()){
    QVector<RowTable*>::iterator it=vec.begin();
    if(!arc->is_empty())
    {
        arc->pop_front();
        delete *it;
        vec.pop_front();
    }
    else
    //sto eliminando la riga del nuovo elemento che non è stato inserito in arc!
    {
        delete (*it)->GetGioiello(); //dealloco il gioiello dallo heap
        delete *it;
        vec.pop_front();
    }
    QTableWidget::removeRow(0);
    InsVal();
}
    else
        QMessageBox::critical(this,"Errore!","Nulla da eliminare!");
}

void Table::InsNew(int i)
{
    insertRow(i);
    RowTable* rowEle=new RowTable(arc,i,this);
    vec.push_back(rowEle);
    setCellWidget(i,0,rowEle->GetMateriale());
    setCellWidget(i,1,rowEle->GetQualita());
    setCellWidget(i,2,rowEle->GetPrezzo());
    setCellWidget(i,3,rowEle->GetTipo());
    setCellWidget(i,4,rowEle->GetMisura());
    setCellWidget(i,5,rowEle->GetSolitario());
    setCellWidget(i,6,rowEle->GetChiusura());
    setCellWidget(i,7,rowEle->GetPendente());
    setCurrentCell(i,0);
}

void Table::NewVal()
{
        for(int i=0;i<arc->size();++i)
        {
            insertRow(i);
            RowTable* rowEle=new RowTable(arc,i,this,(*arc)[i]);
            vec.push_back(rowEle);
            setCellWidget(i,0,rowEle->GetMateriale());
            setCellWidget(i,1,rowEle->GetQualita());
            setCellWidget(i,2,rowEle->GetPrezzo());
            setCellWidget(i,3,rowEle->GetTipo());
            setCellWidget(i,4,rowEle->GetMisura());
            setCellWidget(i,5,rowEle->GetSolitario());
            setCellWidget(i,6,rowEle->GetChiusura());
            setCellWidget(i,7,rowEle->GetPendente());
        }
}

void Table::DelAll()
{
    if(arc->is_empty())
        QMessageBox::critical(this,"Errore!","Container vuoto!");
    else while(!arc->is_empty()) arc->pop_front();
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

void Table::Add(){
    int numrighe = rowCount();
    if(numrighe<=99)
        InsNew(numrighe);
}

void Table::InsVal() {
    while(!arc->is_empty()) arc->pop_front();
    int numrighe = rowCount();
    if(numrighe){
        for(int i=1;i<=numrighe;i++)
        {
            Gioiello* g = GetGio(numrighe-i);
            arc->add(g);
        }
    }
    else QMessageBox::critical(this,"Errore!","Nulla da inserire!");
}
