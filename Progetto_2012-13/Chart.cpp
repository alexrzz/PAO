#include "Chart.h"

Chart::Chart():dati(0),origine(QPointF(0,0)),xdist(0.0)
{
}

Chart::Chart(const QPointF & o, double x, const Dati & d):dati(const_cast<Dati*>(&d)),origine(o),xdist(x)
{
    QPointF inizio(origine.x()+20,origine.y());
    DatiNorm dn(d,550);
    for(int i=0;i<dn.Size();++i)
    {
        QPointF punto(inizio.x()+i*xdist,inizio.y()-dn[i]);
        punti.push_back(punto);
    }

}

int Chart::Size() const
{
    return punti.size();
}

bool Chart::IsEmpty() const
{
    return Size()==0;
}


double Chart::GetDistanza() const
{
    return xdist;
}

QPointF Chart::GetOrigine() const
{
    return origine;
}

double Chart::Spazio() const
{
    return punti[punti.size()-1].x();
}

QPointF& Chart::operator [](int i) const
{
    vector<QPointF>::const_iterator it=punti.begin()+i;
    return const_cast<QPointF&>(*it);
}

Chart::~Chart()
{
    delete dati;
}
