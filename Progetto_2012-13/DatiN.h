#ifndef DATIN_H
#define DATIN_H

#include <vector>
using std::vector;

#include "Dati.h"

class DatiNorm
{
private:
    int max;
    vector<int> norm;
public:
    DatiNorm(const Dati&, int = 100);
    int Max() const;
    int Size() const;
    bool IsEmpty() const;
    int& operator[](int) const;
};

#endif // DATIN_H
