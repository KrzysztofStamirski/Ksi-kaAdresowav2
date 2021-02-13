#include "Wpis.h"


string Wpis::drukuj_krotko(){
    string out;
    if (imie != "") {
        out += imie + " ";
    }
    
    if(nazwisko != "") {
        out += nazwisko + " ";
    }
    
    if(nazwa_firmy != "") {
        out += nazwa_firmy;
    }
    return out;
}

string Wpis::drukuj_wszystko(){
    string out = "Imie: " + imie + "\n";
    out += "Nazwisko: " + nazwisko + "\n";
    out += "Nazwa firmy: " + nazwa_firmy + "\n";
    out += "Telefon: " + telefon + "\n";
    out += "Fax: " + fax + "\n";
    out += "E-mail: " + email + "\n";
    out += "Adres: " + adres + "\n";
    
    return out;
}

string Wpis::get_imie(){
    return imie;
}

string Wpis::get_nazwisko(){
    return nazwisko;
}

string Wpis::get_nazwa_firmy(){
    return nazwa_firmy;
}

string Wpis::get_telefon(){
    return telefon;
}

string Wpis::get_fax(){
    return fax;
}

string Wpis::get_email(){
    return email;
}

string Wpis::get_adres(){
    return adres;
}


Wpis::~Wpis() {
}

