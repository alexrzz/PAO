#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

#include "Valori.h"
#include "Dati.h"
#include "DatiN.h"
#include "Chart.h"
#include "Linechart.h"
#include "Barchart.h"
#include "Pointchart.h"

class Canvas : public QWidget
{
    Q_OBJECT
private:
    QPointF origine;
    QPointF estrX;
    QPointF estrY;
    Valori* val;
    Chart* chart;
public:
     Canvas(Valori*,QWidget *parent = 0);
     void SetOrigine(const QPointF&);
     void SetEstrX(const QPointF&);
     void SetEstrY(const QPointF&);
     ~Canvas();
protected:
     void paintEvent(QPaintEvent *);
public slots:
     void CloseC();
     void Aggiorna();
     void DrawBar();
     void DrawLine();
     void DrawPoint();
};

#endif // CANVAS_H

