#ifndef ANELLO_H
#define ANELLO_H

#include "gioiello.h"

class Anello : public Gioiello
{
private:
    double misura;
    bool solitario;
public:
    Anello(string = "", int = 0, double = 0.0, double = 0.0, bool = false);
    virtual Anello* clone() const; //implementazione covariante
    virtual bool operator==(Gioiello*) const; //override
    double getMisura() const;
    bool getSolitario() const;
    void setMisura(double);
    void setSolitario(bool);
};

#endif // ANELLO_H
