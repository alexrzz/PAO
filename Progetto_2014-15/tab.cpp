#include "tab.h"

Tab::Tab(vector<Utente*>* v, QWidget * parent):QTabWidget(parent), vec(v)
{
    tabella = new Table(vec,this);
    client = new UserWidget(vec,this);
    connect(client,SIGNAL(DBupdated()),this,SLOT(Reload()));
    addTab(tabella,"Admin");
    addTab(client,"Client");
    setCurrentWidget(tabella);
}

void Tab::Reload()
{
    tabella->DelRecords();
    tabella->NewVal();
}


void Tab::NewVal()
{
    tabella->NewVal();
}

void Tab::Add()
{
    int row=tabella->rowCount();
    if(row<=99)
        tabella->InsNew(row);
    else
        QMessageBox::warning(0,"Attenzione","Non è possibile inserire più di 99 elementi");
}

void Tab::Remove()
{
    tabella->Remove();
}

void Tab::DelAll()
{
    tabella->DelAll();
}

void Tab::InsVal()
{
    tabella->InsVal();
}

Table* Tab::getTabella() const
{
    return tabella;
}

UserWidget* Tab::getClient() const
{
    return client;
}

void Tab::setClientTab() {
    setCurrentWidget(client);
}
