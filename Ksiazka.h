#ifndef KSIAZKA_H
#define KSIAZKA_H

#include "Wpis.h"
#include <vector>
#include <memory>

using namespace std;

class Ksiazka {
public:
    Ksiazka();
    void dodaj_wpis(Wpis w);
    void usun_wpis(unsigned int i);
    void zmien_wpis(unsigned int i, Wpis w);
    void lista_wpisow();
    unsigned int liczba_wpisow();
    vector<Wpis> get_wpisy();
    Wpis get_wpis(unsigned int i);
    virtual ~Ksiazka();
private:
    vector<Wpis> wpisy;
};

#endif /* KSIAZKA_H */

