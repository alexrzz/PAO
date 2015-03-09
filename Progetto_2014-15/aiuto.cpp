#include "aiuto.h"

Aiuto::Aiuto(vector<Utente*>* v, QWidget *parent):QDialog(parent), arc(v)
{
    resize(150,150);
    setWindowTitle("DB");
    QFont sansFont("Helvetica [Cronyx]", 12);
    int n = arc->size();
    QString nst=QString::number(n);
    testo = new QLabel("Numero di utenti attualmente nel DB: ");
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
