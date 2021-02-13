#include "Ksiazka.h"

Ksiazka::Ksiazka() {
}

void Ksiazka::dodaj_wpis(Wpis w){
    wpisy.push_back(w);
}

void Ksiazka::usun_wpis(unsigned int i){
    wpisy.erase(wpisy.begin() + i);
}

void Ksiazka::zmien_wpis(unsigned int i, Wpis w){
    wpisy[i] = w;
}

void Ksiazka::lista_wpisow(){
    for(Wpis w: wpisy) {
        w.drukuj_krotko();
    }
}

unsigned int Ksiazka::liczba_wpisow(){
    return wpisy.size();
}

vector<Wpis> Ksiazka::get_wpisy(){
    return wpisy;
}

Wpis Ksiazka::get_wpis(unsigned int i){
    return wpisy[i];
}

Ksiazka::~Ksiazka() {
}

