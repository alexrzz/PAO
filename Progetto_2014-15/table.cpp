#include "table.h"

Table::Table(vector<Utente*>* v,QWidget* parent): QTableWidget(parent),arc(v)
{
    setColumnCount(8);
    QStringList header;
    header<<"Nome"<<"Cognome"<<"Email"<<"Tipo"<<"TitoloDiStudio"<<"Lingue"<<"EsperienzeProfessionali"<<"Presentazione";
    setHorizontalHeaderLabels(header);
    setRowCount(0);
    horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

Utente* Table::GetUt(int i) {
    QVector<TableRow*>::const_iterator it = vec.begin()+i;
    return(*it)->GetUtente();
}

void Table::Remove()
{
    if(rowCount()){
    QVector<TableRow*>::iterator it=vec.end()-1;
    if(!arc->empty())
    {
        arc->pop_back();
        delete *it;
        vec.pop_back();
    }
    else
    //sto eliminando la riga del nuovo elemento che non è stato inserito in arc!
    {
        delete (*it)->GetUtente(); //dealloco l'utente dallo heap
        delete *it;
        vec.pop_back();
    }
    int i = rowCount();
    QTableWidget::removeRow(i-1);
    InsVal();
}
    else
        QMessageBox::critical(this,"Errore!","Nulla da eliminare!");
}

void Table::AddContact(Utente * p)
{
    int i = rowCount();
    insertRow(i);
    TableRow* rowEle=new TableRow(arc,i,this,p);
    vec.push_back(rowEle);
    setCellWidget(i,0,rowEle->GetNome());
    setCellWidget(i,1,rowEle->GetCognome());
    setCellWidget(i,2,rowEle->GetEmail());
    setCellWidget(i,3,rowEle->GetTipo());
    setCellWidget(i,4,rowEle->GetTitoloStudio());
    setCellWidget(i,5,rowEle->GetLingue());
    setCellWidget(i,6,rowEle->GetEspProf());
    setCellWidget(i,7,rowEle->GetPresentazione());
    rowEle->ReadOnly();
}

void Table::RemoveContact(Utente* p)
{
    if(rowCount()){
    QVector<TableRow*>::iterator it=vec.end()-1;
    if(!(p->getContatti().empty()))
    {
        p->removeContatto();
        delete *it;
        vec.pop_back();
    }
    int i = rowCount();
    QTableWidget::removeRow(i-1);
}
    else
        QMessageBox::critical(this,"Errore!","Nulla da eliminare!");
}

void Table::InsNew(int i)
{
    insertRow(i);
    TableRow* rowEle=new TableRow(arc,i,this);
    vec.push_back(rowEle);
    setCellWidget(i,0,rowEle->GetNome());
    setCellWidget(i,1,rowEle->GetCognome());
    setCellWidget(i,2,rowEle->GetEmail());
    setCellWidget(i,3,rowEle->GetTipo());
    setCellWidget(i,4,rowEle->GetTitoloStudio());
    setCellWidget(i,5,rowEle->GetLingue());
    setCellWidget(i,6,rowEle->GetEspProf());
    setCellWidget(i,7,rowEle->GetPresentazione());
    setCurrentCell(i,0);
}

void Table::DelRecords()
{
    for(int i=rowCount();i>=0;i--)
            QTableWidget::removeRow(i);
    for(QVector<TableRow*>::const_iterator it=vec.begin();it!=vec.end();++it)
            delete *it;
    vec.clear();
}

void Table::NewVal()
{
    for(int i=0;i<(signed)arc->size();++i)
    {
        insertRow(i);
        TableRow* rowEle=new TableRow(arc,i,this,(*arc)[i]);
        vec.push_back(rowEle);
        setCellWidget(i,0,rowEle->GetNome());
        setCellWidget(i,1,rowEle->GetCognome());
        setCellWidget(i,2,rowEle->GetEmail());
        setCellWidget(i,3,rowEle->GetTipo());
        setCellWidget(i,4,rowEle->GetTitoloStudio());
        setCellWidget(i,5,rowEle->GetLingue());
        setCellWidget(i,6,rowEle->GetEspProf());
        setCellWidget(i,7,rowEle->GetPresentazione());
    }
}

void Table::NewValC()
{
    for(int i=0;i<(signed)arc->size();++i)
    {
        insertRow(i);
        TableRow* rowEle=new TableRow(arc,i,this,(*arc)[i]);
        vec.push_back(rowEle);
        setCellWidget(i,0,rowEle->GetNome());
        setCellWidget(i,1,rowEle->GetCognome());
        setCellWidget(i,2,rowEle->GetEmail());
        setCellWidget(i,3,rowEle->GetTipo());
        setCellWidget(i,4,rowEle->GetTitoloStudio());
        setCellWidget(i,5,rowEle->GetLingue());
        setCellWidget(i,6,rowEle->GetEspProf());
        setCellWidget(i,7,rowEle->GetPresentazione());
        rowEle->ReadOnly();
    }
}

void Table::DelAll()
{
    if(!arc->empty()) arc->clear();
    for(int i=rowCount();i>=0;i--)
            QTableWidget::removeRow(i);
    for(QVector<TableRow*>::const_iterator it=vec.begin();it!=vec.end();++it)
            delete *it;
    vec.clear();
}

Table::~Table()
{
    for(QVector<TableRow*>::const_iterator it=vec.begin();it!=vec.end();++it)
        delete *it;
}

void Table::Add(){
    int numrighe = rowCount();
    if(numrighe<=99)
        InsNew(numrighe);
}

void Table::InsVal() {
    if(!arc->empty()) arc->clear();
    int numrighe = rowCount();
    if(numrighe){
        for(int i=0;i<numrighe;i++)
        {
            Utente* u = GetUt(i);
            arc->push_back(u);
        }
    }
    else QMessageBox::critical(this,"Errore!","Nulla da inserire!");
}
