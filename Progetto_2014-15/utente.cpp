#include "utente.h"

Utente::Utente(string n, string c, string e, vector<Utente*> v) : nome(n), cognome(c), email(e), contatti(v){}

bool Utente::operator ==(Utente* u) const {
    return nome == u->getNome() && cognome == u->getCognome() && email == u->getEmail() && contatti == u->getContatti();
}

string Utente::getNome() const {
    return nome;
}

string Utente::getCognome() const {
    return cognome;
}

string Utente::getEmail() const {
    return email;
}

vector <Utente*> Utente::getContatti() const {
    return contatti;
}

void Utente::setNome(string n) {
    nome = n;
}

void Utente::setCognome(string c) {
    cognome = c;
}

void Utente::setEmail(string e) {
    email = e;
}

void Utente::addContatto(Utente * u) {
    contatti.push_back(u->clone());
}

void Utente::removeContatto() {
    contatti.pop_back();
}
