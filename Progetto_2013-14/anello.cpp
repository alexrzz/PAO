#include "anello.h"

Anello::Anello(string m, int q, double p, double mi, bool s) : Gioiello(m, q, p), misura(mi), solitario(s) {}

Anello* Anello::clone()const {
    return new Anello(*this);
}

bool Anello::operator==(Gioiello* p) const {
    Anello* q = dynamic_cast<Anello*>(p);
    if(q)
        return (this->Gioiello::operator==(p) && misura == q->misura && solitario == q->solitario);
}

double Anello::getMisura() const {
    return misura;
}

bool Anello::getSolitario() const {
    return solitario;
}

void Anello::setMisura(double m) {
    misura = m;
}

void Anello::setSolitario(bool s) {
    solitario = s;
}
