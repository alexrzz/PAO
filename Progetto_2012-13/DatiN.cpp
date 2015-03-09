#include "DatiN.h"

DatiNorm::DatiNorm(const Dati & d,int massimo):max(massimo)
{
    int maxt=d.max();
    for(int i=0;i<d.Size();++i)
    {
        int value=max*d[i]/maxt;
        norm.push_back(value);
    }
}

int DatiNorm::Max() const
{
    return max;
}

int DatiNorm::Size() const
{
    return norm.size();
}

bool DatiNorm::IsEmpty() const
{
    return norm.size()==0;
}

int& DatiNorm::operator [](int i) const
{
    vector<int>::const_iterator it=norm.begin()+i;
    return const_cast<int&>(*it);
}
