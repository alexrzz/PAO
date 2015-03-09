#include "aiuto.h"

Aiuto::Aiuto(Container<Gioiello*>* c, QWidget *parent):QDialog(parent), arc(c)
{
    resize(150,150);
    setWindowTitle("Container");
    QFont sansFont("Helvetica [Cronyx]", 12);
    int n = arc->size();
    QString nst=QString::number(n);
    testo = new QLabel("Numero di elementi attualmente nel container: ");
    testo->setWordWrap(true);
    testo->setFont(sansFont);
    conta = new QLabel(nst);
    conta->setWordWrap(true);
    conta->setFont(sansFont);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(testo);
    layout->addWidget(conta);
    setLayout(layout);
}
