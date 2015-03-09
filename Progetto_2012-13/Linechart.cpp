#include "Linechart.h"

LineChart::LineChart(const QPointF & i, double x, const Dati& dn):Chart(i,x,dn)
{
}

void LineChart::Draw(QPainter &p) const
{
    p.setPen(QPen(Qt::black,4));
    for(int i=0;i<Size()-1;++i)
    {
        QLineF linea(punti[i],punti[i+1]);
        p.drawLine(linea);
    }
    if(Size()>1)
    {
        for(int i=0;i<Size();++i)
            {
            QString index;
            index.setNum(i+1);
            p.setPen(QPen(Qt::black,3));
            QPointF punto(punti[i].x(),GetOrigine().y()+20);
            p.drawText(punto,index);
            }
    }
}
