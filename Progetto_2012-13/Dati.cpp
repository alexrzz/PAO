#include "Dati.h"

Dati::Dati(const Valori& v)
{
    for(int i=0;i<v.Dim();++i)
    {
        int val=v[i]->GetPunti();
        d.push_back(val);
    }
}

int Dati::max() const
{
    vector<int>::const_iterator it=d.begin();
    int massimo=*it;
    ++it;
    for(;it!=d.end();++it)
    {
        if((*it)>massimo)
            massimo=(*it);
    }
    return massimo;
}

int Dati::Size() const
{
    return d.size();
}

bool Dati::IsEmpty() const
{
    return d.size()==0;
}

int& Dati::operator [](int i) const
{
    vector<int>::const_iterator it=d.begin()+i;
    return const_cast<int&>(*it);
}
