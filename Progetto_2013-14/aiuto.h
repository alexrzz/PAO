#ifndef AIUTO_H
#define AIUTO_H
#include "container.h"
#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
class Aiuto : public QDialog
{
Q_OBJECT
public:
      Aiuto(Container<Gioiello*>* =0,QWidget *parent =0);
private:
      Container<Gioiello*>* arc;
      QLabel* testo;
      QLabel* conta;
};

#endif // AIUTO_H
