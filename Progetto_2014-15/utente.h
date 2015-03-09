#ifndef UTENTE_H
#define UTENTE_H
#include <string>
#include <vector>

using std::string;
using std::vector;

class Utente
{
private:
    string nome;
    string cognome;
    string email; // id univoco, deve essere unica nel db
    vector<Utente*> contatti; // la rete di contatti dell'utente
public:
    Utente(string, string, string, vector<Utente*>);
    Utente() {}
    virtual Utente* clone() const =0;
    virtual ~Utente() {}
    virtual bool operator==(Utente*) const;
    string getNome() const;
    string getCognome() const;
    string getEmail() const;
    vector<Utente*> getContatti() const;
    void setNome(string);
    void setCognome(string);
    void setEmail(string);
    void addContatto(Utente*);
    void removeContatto(); // rimozione ultimo contatto, per ragioni di efficienza
};

#endif // UTENTE_H
