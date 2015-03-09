#ifndef UTENTEBASIC_H
#define UTENTEBASIC_H

#include "utente.h"

class UtenteBasic : public Utente
{
private:
    string titoloStudio;
    string lingue;
public:
    UtenteBasic(string, string, string, vector<Utente*>, string, string);
    UtenteBasic() {}
    virtual ~UtenteBasic() {}
    virtual UtenteBasic* clone() const; // impl. cov.
    virtual bool operator==(Utente*) const;
    string getTitoloStudio() const;
    string getLingue() const;
    void setTitoloStudio(string);
    void setLingue(string);
};

#endif // UTENTEBASIC_H
