#ifndef AIUTO_H
#define AIUTO_H

#include <QDialog>
#include <QLabel>
#include <QFont>
#include <QVBoxLayout>
class Aiuto : public QDialog
{
Q_OBJECT
public:
      Aiuto(QWidget *parent =0);
private:
      QLabel* testo;
};

#endif // AIUTO_H
