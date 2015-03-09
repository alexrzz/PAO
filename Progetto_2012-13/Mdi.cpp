#include "Mdi.h"

Mdi::Mdi(Valori* v,QWidget *parent):QMdiArea(parent),val(v)
{
    area=new QScrollArea();
    tabella=new Table(val);
    view=new Canvas(val,this);
    tabella->setWindowTitle("Dati");
    area->setWindowTitle("Grafico");
    setAttribute(Qt::WA_DeleteOnClose);
    setViewMode(TabbedView);
    area->setWidget(view);
    addSubWindow(area);
    addSubWindow(tabella);
    connect(this,SIGNAL(Close()),view,SLOT(CloseChart()));
    connect(tabella,SIGNAL(Changed()),view,SLOT(Aggiorna()));
}

void Mdi::Open()
{
    tabella->NewVal();
}

void Mdi::Add()
{
    int numrighe = tabella->rowCount();
    if(numrighe<=99)
        tabella->InsNew(numrighe);
    else
        QMessageBox::critical(0,"Errore","Impossibile inserire più di 99 elementi");
}

void Mdi::InsVal()
{
    int numrighe = tabella->rowCount();
    Squadra* sq=tabella->GetSq(numrighe-1);
    if(sq->GetNome()=="")
        QMessageBox::critical(0,"Errore","Inserimento non riuscito");
    val->Add(*sq);
}

void Mdi::Close()
{
    tabella->DelAll();
    view->CloseC();
}

void Mdi::Line()
{
    view->DrawLine();
}

void Mdi::Bar()
{
    view->DrawBar();
}

void Mdi::Point()
{
    view->DrawPoint();
}
