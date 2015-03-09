#include "orecchino.h"

Orecchino::Orecchino(string m, int q, double p, string c, bool pe) : Gioiello(m, q, p), chiusura(c), pendente(pe) {}

Orecchino* Orecchino::clone() const {
    return new Orecchino(*this);
}

bool Orecchino::operator ==(Gioiello* p) const {
    Orecchino* q = dynamic_cast<Orecchino*>(p);
    if(q)
        return (this->Gioiello::operator ==(p) && chiusura == q->chiusura && pendente == q->pendente);
}

string Orecchino::getChiusura() const {
    return chiusura;
}

bool Orecchino::getPendente() const {
    return pendente;
}

void Orecchino::setChiusura(string ch) {
    chiusura = ch;
}

void Orecchino::setPendente(bool p) {
    pendente = p;
}
