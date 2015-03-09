#include "gioiello.h"

Gioiello::Gioiello(string m, int q, double p): materiale(m), qualita(q), prezzo(p) {}

bool Gioiello::operator ==(Gioiello* p) const {
    return (materiale == p->materiale && qualita == p->qualita && prezzo == p->prezzo);
}

string Gioiello::getMateriale() const {
    return materiale;
}

int Gioiello::getQualita() const {
    return qualita;
}

double Gioiello::getPrezzo() const {
    return prezzo;
}

void Gioiello::setMateriale(string m) {
    materiale = m;
}

void Gioiello::setQualita(int q) {
    qualita = q;
}

void Gioiello::setPrezzo(double p) {
prezzo = p;
}
