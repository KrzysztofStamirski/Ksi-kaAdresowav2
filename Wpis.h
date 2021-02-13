#ifndef WPIS_H
#define WPIS_H

#include <string>

using namespace std;

class Wpis {
public:
    Wpis(string i, string n, string nf, string t, string f, string e, string a):imie(i), nazwisko(n), nazwa_firmy(nf), telefon(t), fax(f), email(e), adres(a) {};
    string drukuj_krotko();
    string drukuj_wszystko();
    string get_imie();
    string get_nazwisko();
    string get_nazwa_firmy();
    string get_telefon();
    string get_fax();
    string get_email();
    string get_adres();
    virtual ~Wpis();
private:
    string imie;
    string nazwisko;
    string nazwa_firmy;
    string telefon;
    string fax;
    string email;
    string adres;
};

#endif /* WPIS_H */

