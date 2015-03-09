#include "Aiuto.h"

Aiuto::Aiuto(QWidget *parent):QDialog(parent)
{
    resize(300,300);
    setWindowTitle("Guida");
    QFont sansFont("Helvetica [Cronyx]", 12);
    testo = new QLabel("Se si cerca di visualizzare un grafico senza aver inserito dati il programma termina. Per inserire un nuovo dato cliccare su Aggiungi o premere CTRL-N. Quindi compilare i campi Squadra e Punti, infine cliccare Inserisci o premere F5. I nuovi dati inseriti saranno quindi visualizzabili su di un grafico a scelta. Per salvare i dati posizionarsi sulla finestra Dati e cliccare Salva o premere CTRL-S. ");
    testo->setWordWrap(true);
    testo->setFont(sansFont);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(testo);
    setLayout(layout);
}
