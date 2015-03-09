#ifndef UTENTEBUSINESS_H
#define UTENTEBUSINESS_H

#include "utentebasic.h"

class UtenteBusiness : public UtenteBasic
{
private:
    string espProf;
public:
    UtenteBusiness(string, string, string, vector<Utente*>, string, string, string);
    UtenteBusiness() {}
    virtual ~UtenteBusiness() {}
    virtual UtenteBusiness* clone() const;
    virtual bool operator==(Utente*) const;
    string getEspProf() const;
    void setEspProf(string);
};

#endif // UTENTEBUSINESS_H
