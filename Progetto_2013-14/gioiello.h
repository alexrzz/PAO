#ifndef GIOIELLO_H
#define GIOIELLO_H

#include <string>
using std::string;

class Gioiello {
private:
    string materiale;
    int qualita;
    double prezzo;
public:
    Gioiello(string = "", int = 0, double = 0.0);
    virtual ~Gioiello() {}
    virtual Gioiello* clone() const =0; // metodo virtuale puro
    virtual bool operator==(Gioiello*) const;
    string getMateriale() const;
    int getQualita() const;
    double getPrezzo() const;
    void setMateriale(string);
    void setQualita(int);
    void setPrezzo(double);
};

#endif // GIOIELLO_H
