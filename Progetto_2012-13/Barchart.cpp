#include "Barchart.h"

BarChart::BarChart(const QPointF &o, double x,double w,const Dati &dn):Chart(QPoint(o.x(),o.y()-4),x+w,dn),width(w)
{
}

double BarChart::GetWidth() const
{
    return width;
}

double BarChart::Spazio() const
{
        return punti[punti.size()-1].x()+width;
}

void BarChart::Draw(QPainter& p) const
{
    for(int i=0;i<Size();i++)
        {
            p.setPen(QPen(Qt::red,4));
            QRectF rect(punti[i],QSizeF(width,GetOrigine().y()-punti[i].y()));
            p.drawRect(rect);
            QRectF rect1(punti[i]+QPointF(1,1),QSize(width-1,(GetOrigine().y()-punti[i].y()-1)));
            p.fillRect(rect1, QBrush(QColor(Qt::darkYellow),Qt::SolidPattern));
            p.setPen(QPen(Qt::black,3));
            QString index;
            index.setNum(i+1);
            QPointF punto(punti[i].x()+width/2-1 ,GetOrigine().y()+20);
            p.drawText(punto,index);
        }
}
