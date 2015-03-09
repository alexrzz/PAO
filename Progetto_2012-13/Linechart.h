#ifndef LINECHART_H
#define LINECHART_H

#include <QPointF>

#include "Chart.h"

class LineChart : public Chart
{
public:
    LineChart(const QPointF&,double,const Dati&);
    virtual void Draw(QPainter &) const;
};

#endif // LINECHART_H
