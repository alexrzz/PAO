#include "Valori.h"

Valori::Valori()
{
}

void Valori::Add(const Squadra &s)
{
    Squadra* sq=const_cast<Squadra*>(&s);
    ogg.push_back(sq);
}

void Valori::Del(int i)
{
    vector<Squadra*>::iterator it=ogg.begin()+i;
    if(*it)
        delete *it;
    ogg.erase(it);
}

int Valori::Dim() const
{
    return ogg.size();
}

bool Valori::IsEmpty() const
{
    return ogg.size()==0;
}

void Valori::DelAll()
{
    for(vector<Squadra*>::const_iterator it=ogg.begin();it!=ogg.end();++it)
        delete *it;
    ogg.clear();
}


void Valori::Change(int i, const Squadra & s)
{
    Squadra* sq=const_cast<Squadra*>(&s);
    delete ogg[i];
    ogg[i]=sq;
}

Squadra* Valori::operator [](int i) const
{
    vector<Squadra*>::const_iterator it=ogg.begin()+i;
    return *it;
}

bool Valori::operator ==(const Valori& v) const
{
    bool ok=true;
    if(Dim()!=v.Dim())
        ok=false;
    for(int i=0;i<Dim()&& ok;++i)
        if((*ogg[i])!=(*v.ogg[i]))
            ok=false;
    return ok;
}

bool Valori::operator !=(const Valori& v) const
{
    bool ok=true;
    if(Dim()!=v.Dim())
        ok=false;
    for(int i=0;i<Dim()&& ok;++i)
        if((*ogg[i])!=(*v.ogg[i]))
            ok=false;
    return !ok;
}

Valori::~Valori()
{
    for(vector<Squadra*>::iterator it=ogg.begin();it!=ogg.end();++it)
         delete *it;
}
