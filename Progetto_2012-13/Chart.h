#ifndef CHART_H
#define CHART_H

#include<QPainter>
#include<vector>
using std::vector;

#include "DatiN.h"
#include "Dati.h"

class Chart
{
protected:
    vector<QPointF> punti;
private:
    QPointF origine;
    double xdist;
    Dati* dati;
public:
    Chart();
    Chart(const QPointF&,double,const Dati&);
    int Size() const;
    bool IsEmpty() const;
    double GetDistanza() const;
    QPointF GetOrigine() const;
    virtual double Spazio() const;
    virtual QPointF& operator[](int) const;
    virtual void Draw(QPainter&) const=0;
    virtual ~Chart();
};

#endif // CHART_H
