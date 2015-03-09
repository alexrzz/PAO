#ifndef AIUTO_H
#define AIUTO_H
#include "utente.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
#include <vector>

using std::vector;

class Aiuto : public QDialog
{
Q_OBJECT
public:
      Aiuto(vector<Utente*>* =0,QWidget *parent =0);
private:
      vector<Utente*>* arc;
      QLabel* testo;
      QLabel* conta;
};

#endif // AIUTO_H
