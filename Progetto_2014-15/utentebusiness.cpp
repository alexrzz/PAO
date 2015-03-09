#include "utentebusiness.h"

UtenteBusiness::UtenteBusiness(string n, string c, string e, vector<Utente*> v, string ts, string l, string es):UtenteBasic(n,c,e,v,ts,l),espProf(es){}

bool UtenteBusiness::operator==(Utente* u) const {
    UtenteBusiness* ub = dynamic_cast<UtenteBusiness*>(u);
    if(ub)
        return Utente::operator ==(ub) && UtenteBasic::operator ==(ub) && espProf == ub->getEspProf();
    else return false;
}

UtenteBusiness* UtenteBusiness::clone() const {
    return new UtenteBusiness(*this);
}

string UtenteBusiness::getEspProf() const {
    return espProf;
}

void UtenteBusiness::setEspProf(string es) {
    espProf=es;
}
