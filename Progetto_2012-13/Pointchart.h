#ifndef POINTCHART_H
#define POINTCHART_H

#include "Chart.h"

class PointChart : public Chart
{
public:
    PointChart(const QPointF&,double,const Dati&);
    virtual void Draw(QPainter &) const;
};

#endif // POINTCHART_H
