#ifndef VALORI_H
#define VALORI_H

#include "Squadra.h"
#include <vector>
using std::vector;

class Valori
{
private:
    vector<Squadra*> ogg;
public:
    Valori();
    void Add(const Squadra&);
    void Del(int);
    int Dim() const;
    bool IsEmpty() const;
    void DelAll();
    void Change(int,const Squadra&);
    Squadra* operator[](int i) const;
    bool operator==(const Valori&) const;
    bool operator!=(const Valori&) const;
    ~Valori();
};

#endif // VALORI_H

