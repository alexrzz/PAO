#ifndef DATI_H
#define DATI_H

#include<vector>
using std::vector;

#include "Valori.h"

class Dati
{
private:
    vector<int> d;
public:
    Dati(const Valori&);
    int max() const;
    int Size() const;
    bool IsEmpty() const;
    int& operator[](int) const;
};

#endif // DATI_H
