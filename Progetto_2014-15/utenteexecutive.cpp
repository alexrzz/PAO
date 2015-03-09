#include "utenteexecutive.h"

UtenteExecutive::UtenteExecutive(string n, string c, string e, vector<Utente*> v, string ts, string l, string es, string p) : UtenteBusiness(n,c,e,v,ts,l,es), presentazione(p) {}

bool UtenteExecutive::operator ==(Utente* u) const {
    UtenteExecutive* ue = dynamic_cast<UtenteExecutive*> (u);
    if(ue)
        return UtenteBusiness::operator ==(ue) && presentazione==ue->getPresentazione();
    else return false;
}

string UtenteExecutive::getPresentazione() const {
    return presentazione;
}

void UtenteExecutive::setPresentazione(string p) {
    presentazione = p;
}

UtenteExecutive* UtenteExecutive::clone() const {
    return new UtenteExecutive(*this);
}
