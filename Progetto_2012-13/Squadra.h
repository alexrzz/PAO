#ifndef SQUADRA_H
#define SQUADRA_H

#include<string>
using std::string;

class Squadra
{
private:
    string nome;
    int punti;
public:
    Squadra();
    Squadra(string,int);
    string GetNome() const;
    int GetPunti() const;
    void SetNome(string);
    void SetPunti(int);
    bool operator==(const Squadra&) const;
    bool operator!=(const Squadra&) const;
};

#endif // SQUADRA_H
