#ifndef BARCHART_H
#define BARCHART_H

#include "Chart.h"

class BarChart : public Chart
{
private:
    double width;
public:
    BarChart(const QPointF&,double,double,const Dati&);
    double GetWidth() const;
    virtual double Spazio() const;
    virtual void Draw(QPainter &) const;
};

#endif // BARCHART_H
