#ifndef UTENTEEXECUTIVE_H
#define UTENTEEXECUTIVE_H

#include "utentebusiness.h"

class UtenteExecutive : public UtenteBusiness
{
private:
    string presentazione;
public:
    UtenteExecutive(string, string, string, vector<Utente*>, string, string, string, string);
    UtenteExecutive(){}
    virtual ~UtenteExecutive(){}
    virtual bool operator==(Utente*) const;
    virtual UtenteExecutive* clone() const;
    string getPresentazione() const;
    void setPresentazione(string);
};

#endif // UTENTEEXECUTIVE_H
