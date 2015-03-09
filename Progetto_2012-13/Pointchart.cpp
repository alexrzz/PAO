#include "Pointchart.h"

PointChart::PointChart(const QPointF & o, double x, const Dati &dn):Chart(o,x,dn)
{
}
void PointChart::Draw(QPainter &p) const
{

    for(int i=0;i<Size();++i)
    {
        p.setPen(QPen(Qt::black,5));
        QPointF punto=punti[i];
        p.drawPoint(punto);
        QString index;
        index.setNum(i+1);
        p.setPen(QPen(Qt::black,3));
        QPointF puntoi(punti[i].x(),GetOrigine().y()+20);
        p.drawText(puntoi,index);
    }
}
