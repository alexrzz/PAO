#include "utentebasic.h"

UtenteBasic::UtenteBasic(string n, string c, string e, vector<Utente*> v, string ts, string l): Utente(n, c, e, v), titoloStudio(ts), lingue(l) {}

bool UtenteBasic::operator ==(Utente* u) const {
    UtenteBasic* ub = dynamic_cast<UtenteBasic*>(u);
    if(ub)
        return Utente::operator ==(ub) && titoloStudio==ub->getTitoloStudio() && lingue==ub->getLingue();
    else return false;
}

string UtenteBasic::getTitoloStudio() const {
    return titoloStudio;
}

string UtenteBasic::getLingue() const {
    return lingue;
}

UtenteBasic* UtenteBasic::clone() const {
    return new UtenteBasic(*this);
}

void UtenteBasic::setTitoloStudio(string ts) {
    titoloStudio=ts;
}

void UtenteBasic::setLingue(string l) {
    lingue=l;
}
