#include "Squadra.h"

Squadra::Squadra():nome(""),punti(0)
{
}

Squadra::Squadra(string n, int p):nome(n),punti(p)
{
}

string Squadra::GetNome() const
{
    return nome;
}

int Squadra::GetPunti() const
{
    return punti;
}

void Squadra::SetNome(string n)
{
    nome=n;
}

void Squadra::SetPunti(int p)
{
    punti=p;
}

bool Squadra::operator==(const Squadra& s) const
{
    if(s.GetNome()==this->GetNome()) return true;
    return false;
}

bool Squadra::operator !=(const Squadra& s) const
{
    if (s.GetNome()!=this->GetNome()) return true;
    return false;
}
