#ifndef TAB_H
#define TAB_H

#include <QTabWidget>
#include <vector>
#include "table.h"
#include "userwidget.h"

class Tab : public QTabWidget
{
    Q_OBJECT
private:
    vector<Utente*>* vec;
    Table* tabella;
    UserWidget* client;
public:
    Tab(vector<Utente*>*,QWidget * parent = 0);
    Table* getTabella() const;
    UserWidget* getClient() const;
public slots:
    void NewVal();
    void Add();
    void Remove();
    void InsVal();
    void DelAll();
    void setClientTab();
    void Reload();
};

#endif // TAB_H
