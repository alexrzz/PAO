#ifndef CONTAINER_H
#define CONTAINER_H

#include "gioiello.h"
#include "anello.h"
#include "orecchino.h"
#include <iostream>
using std::cerr;
using std::endl;

template<class T>
class Container {
    friend class Iteratore;
private:
    //template implicito di classe annidato associato
    class ContainerItem {
    public:
        ContainerItem(); //costruttore di default
        ContainerItem(const T&, ContainerItem* = 0); //costruttore a 1/2 parametri
        T info;
        ContainerItem* next;
    };
    ContainerItem* primo;
    ContainerItem* ultimo;
    static ContainerItem* copia(ContainerItem*);
    static void distruggi(ContainerItem*);
public:
    class Iteratore {
        friend class Container;
    private:
        Container<T>::ContainerItem* punt; //ContainerItem puntato dall'iteratore
    public:
        bool operator==(Iteratore) const; //uguaglianza
        bool operator!=(Iteratore) const; //disuguaglianza
        Iteratore& operator++(); //incremento prefisso
        Iteratore operator++(int); //incremento postfisso
        Container<T>::ContainerItem& operator*() const; //dereferenziazione
        Container<T>::ContainerItem* operator->() const; //accesso a membro
    };
    Container(); //costruttore di default
    Container (const Container<T>&); //copia profonda
    ~Container(); //distruzione profonda
    Container<T>& operator=(const Container<T>&); //assegnazione profonda
    bool is_empty() const;
    void add(const T&); // inserimento in coda
    void pop_front(); //rimozione in testa
    bool search(const T&) const; //ricerca
    void modify(T&, T&); //modifica
    void deleteAll(); //svuotamento
    int size() const;//conteggio elementi
    Iteratore begin() const;
    Iteratore end() const;
    T& operator[](Iteratore) const;
    T& operator[](int) const;
};

template <class T>
Container<T>::ContainerItem::ContainerItem() {}

template <class T>
Container<T>::ContainerItem::ContainerItem(const T& val, ContainerItem* s) : info(val), next(s) {}

template <class T>
typename Container<T>::ContainerItem* Container<T>::copia(ContainerItem* ci) {
    if(!ci) return 0; //caso base: lista vuota
    else
        //passo induttivo:
        //per induzione copia(ci->next) è la copia della coda di ci
        //e quindi inserisco il primo nodo di ci in testa alla lista copia(ci->next)
        return new ContainerItem(ci->info, copia(ci->next));
}

template <class T>
void Container<T>::distruggi(ContainerItem* ci) {
    //caso base: lista vuota, nulla da fare
    if(ci) {
        //passo induttivo:
        //per induzione distruggi(ci->next) è dealloca la coda di ci
        //e quindi rimane da deallocare solamente il primo nodo di ci
        distruggi(ci->next);
    delete ci;
    }
}

template <class T>
bool Container<T>::Iteratore::operator==(Iteratore it) const {
    return punt == it.punt;
}

template <class T>
bool Container<T>::Iteratore::operator!=(Iteratore it) const {
    return punt != it.punt;
}

template <class T>
typename Container<T>::ContainerItem& Container<T>::Iteratore::operator*() const {
    return *punt;
}

template <class T>
typename Container<T>::ContainerItem* Container<T>::Iteratore::operator->() const {
    return punt;
}

template <class T>
typename Container<T>::Iteratore& Container<T>::Iteratore::operator++() {
    if(punt) punt = punt->next; //side-effect
    return *this;
} //se punt == 0 non faccio nulla

template <class T>
typename Container<T>::Iteratore Container<T>::Iteratore::operator++(int) {
    Iteratore aux = *this;
    if(punt) punt = punt->next; //side-effect
    return aux;
} //se punt == 0 non faccio nulla

template <class T>
Container<T>::Container() : primo(0), ultimo(0) {}

template <class T>
Container<T>::Container(const Container<T>& c) : primo(copia(c.primo)), ultimo(copia(c.ultimo)) {}

template <class T>
Container<T>::~Container() {
    if(!is_empty()) distruggi(primo);
}

template <class T>
Container<T>& Container<T>::operator=(const Container<T>& c) {
    if(this != &c) { //operator != tra puntatori
        if(!is_empty()) distruggi(primo);
        primo = copia(c.primo);
    }
    return *this;
}

template <class T>
bool Container<T>::is_empty() const { return (primo == 0); }

template <class T>
void Container<T>::add(const T& val) {
    ContainerItem* p = new ContainerItem(val);
    if(is_empty())
        primo = ultimo = p;
    else{ //aggiungo in coda
        ultimo->next = p;
        ultimo = p;
    }
}

template<class T>
void Container<T>::pop_front() {
    if (is_empty())
        cerr<<"pop_front() su contenitore vuoto"<<endl;
    else {
        ContainerItem* p = primo;
        primo = primo->next;
        delete p;
    }
}

template<class T>
bool Container<T>::search(const T& val) const {
    if (is_empty())
        cerr<<"search() su contenitore vuoto"<<endl;
    else {
        Container<T>::Iteratore it = begin();
        bool trovato = false;
        for ( ; it != end(); it++) {
            if(it->info->getMateriale() == val->getMateriale()) //non è codice estensibile, però con it->info == val non ci sono riuscito
                trovato = true;                          //probabilmente perchè è una ricerca su singolo campo e non su oggetto
        }                                              //pertanto operator== ridefinito non è adatto a questo utilizzo
        return trovato;
    }
}

template<class T>
void Container<T>::modify(T& old_val, T& val) {
    Container<T>::Iteratore it = begin();
    for ( ; it != end(); it++)
        if(it->info == old_val){ //si richiede operator== per tipo T
            delete it->info;
            it->info = val;}
}

template<class T>
int Container<T>::size() const {
    int conta=0;
    if(is_empty()) return conta;
    else { //primo !=0
        Container<T>::Iteratore it = begin();
        for ( ; it != end(); it++) {
            conta++;
        }
        return conta;
    }
}

template<class T>
void Container<T>::deleteAll() {
    if(!is_empty()) distruggi(primo);
}

template<class T>
typename Container<T>::Iteratore Container<T>::begin() const  {
    Iteratore aux;
    aux.punt = primo; //per amicizia
    return aux;
}

template<class T>
typename Container<T>::Iteratore Container<T>::end() const  {
    Iteratore aux;
    aux.punt = ultimo->next; //per amicizia
    return aux;
}

template <class T>
T& Container<T>::operator[](Container<T>::Iteratore it) const {
    return (it.punt)->info; //per amicizia
}

template <class T>
T& Container<T>::operator[](int i) const {
    Iteratore it = begin();
    for(int j=0; j<i ; j++) {
        it++;
    }
    return (*this)[it];
}

#endif // CONTAINER_H
