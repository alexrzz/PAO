#include "findwindow.h"

FindWindow::FindWindow(Container<Gioiello *>* c, QWidget *parent): QDialog(parent), arc(c) {
    setWindowTitle("Cerca un materiale");
    resize(350,350);
    setModal(true);
    QDialog::reject();
    QLabel* label=new QLabel("Inserisci il materiale da cercare");
    trova= new QLineEdit();
    QHBoxLayout* inputlayout= new QHBoxLayout();
    inputlayout->addWidget(label);
    inputlayout->addWidget(trova);
    ok=new QPushButton(tr("ok"));
    annulla=new QPushButton(tr("Annulla"));
    ok->setFont(QFont("Helvetica [Cronyx]", 12));
    annulla->setFont(QFont("Helvetica [Cronyx]", 12));
    QDialogButtonBox* button=new QDialogButtonBox(Qt::Horizontal);
    button->addButton(ok,QDialogButtonBox::ActionRole);
    button->addButton(annulla,QDialogButtonBox::ActionRole);
    QVBoxLayout* container=new QVBoxLayout();
    container->addLayout(inputlayout);
    container->addWidget(button);
    setLayout(container);
    connect(ok,SIGNAL(clicked()),this,SLOT(clickedOk()));
    connect(annulla,SIGNAL(clicked()),this,SLOT(close()));
}

void FindWindow::clickedOk() {
    if(trova->text()!=""){
        QString tr=trova->text();
        string trst=tr.toStdString();
        Gioiello* g = new Anello(trst);
        Gioiello* p = new Orecchino(trst);
        if(arc->is_empty()) QMessageBox::critical(this,"Errore!","Contenitore vuoto!");
        else if(arc->search(g)||arc->search(p)) QMessageBox::information(this,"Trovato!","Il materiale e' presente in archivio!");
        else QMessageBox::information(this,"Assente!","Il materiale non e' presente in archivio!");
    }
    else QMessageBox::critical(this,"Errore!","Nulla da cercare!");
}

