#ifndef ORECCHINO_H
#define ORECCHINO_H

#include "gioiello.h"

class Orecchino : public Gioiello
{
private:
    string chiusura;
    bool pendente;
public:
    Orecchino(string = "", int = 0, double = 0.0, string = "", bool = false);
    virtual Orecchino* clone() const; //implementazione covariante
    virtual bool operator==(Gioiello*) const; //override
    string getChiusura() const;
    bool getPendente() const;
    void setChiusura(string);
    void setPendente(bool);
};

#endif // ORECCHINO_H
