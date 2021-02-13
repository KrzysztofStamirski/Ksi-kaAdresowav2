#include <cstdlib>
#include <iostream>
#include <algorithm>

#include "Ksiazka.h"
#include "Wpis.h"

using namespace std;

void intro(){
    cout << "Wybierz akcję:" << endl;
    cout << "dw - dodaj wpis" << endl;
    cout << "zw - zmień wpis" << endl;
    cout << "uw - usuń wpis" << endl;
    cout << "lw - lista wpisów" << endl;
    cout << "pw - pokaż wpis" << endl;
    cout << "op - opuść program i zachowaj zmiany" << endl << endl;
}

void dokonsoli(string s){
    cout << s << endl;
}

string pole(string tytul, bool mozna_omin = true, string domysl = ""){
    string pole;
    if(mozna_omin) {
        dokonsoli("<Enter> żeby ominąć");
    }
    if (domysl != "") {
        cout << tytul << "<" + domysl + ">: ";
    } else {
        cout << tytul << ": ";
    }
    cin.sync();
    if (mozna_omin) {
        getline(cin >> ws, pole);
    } else {
        cin >> pole;
    }
    if(domysl != "" && pole == "") {
        pole = domysl;
    }
    return pole;
}

int main(int argc, char** argv) {
    Ksiazka *ksiazka = new Ksiazka();
    
    intro();
    bool run = true;
    string komendy[] = {"dw", "zw", "uw", "lw", "pw", "op"};
    string komenda;
    do {
        cout << "> ";
        cin >> komenda;
        bool komendaZnana = find(begin(komendy), end(komendy), komenda) != end(komendy);
        if(!komendaZnana) {
            dokonsoli("Nieznana komenda: " + komenda);
            intro();
            continue;
        }
        
        if(komenda == "dw") {
            string imie = pole("Imie");
            string nazwisko = pole("Nazwisko");
            string nf = pole("Nazwa firmy");
            
            if (imie == "" && nazwisko == "" && nf == "") {
                dokonsoli("Wpis musi zawierać przynajmniej jedną z trzech danych: imie, nazwisko, nazwa firmy.");
                continue;
            }
            
            string tel = pole("Telefon");
            string fax = pole("Fax");
            string email;
            size_t malpa;
            do {
                email = pole("E-mail");
                if (email != "") {
                    malpa = email.find("@");
                    if(malpa == string::npos) {
                        dokonsoli("E-mail musi zawierać @");
                    }
                }
            } while(malpa == string::npos);
            string adres = pole("Adres");
            ksiazka->dodaj_wpis(Wpis(imie, nazwisko, nf, tel, fax, email, adres));
            dokonsoli("Dodany nowy wpis do książki adresowej.");
        }
        
        if(komenda == "zw") {
            unsigned int numer = stoi(pole("Numer wpisu", false));
            if (numer < 1) {
                dokonsoli("Numer wpisu nie może być mniejszy niż 1");
                continue;
            }
            
            if (numer > ksiazka->liczba_wpisow()) {
                dokonsoli("Wpis #" + to_string(numer) + " nie istnieje");
                continue;
            }
            
            numer -= 1;
            Wpis w = ksiazka->get_wpis(numer);
            dokonsoli("Zmienić: " + w.drukuj_krotko());
            string tak = pole("Potwierdź z 'tak'", false);
            if (tak == "tak") {
                string imie = pole("Imie", true, w.get_imie());
                string nazwisko = pole("Nazwisko", true, w.get_nazwisko());
                string nf = pole("Nazwa firmy", true, w.get_nazwa_firmy());
                string tel = pole("Telefon", true, w.get_telefon());
                string fax = pole("Fax", true, w.get_fax());
                string email;
                size_t malpa;
                do {
                    email = pole("E-mail", true, w.get_email());
                    if (email != "") {
                        malpa = email.find("@");
                        if(malpa == string::npos) {
                            dokonsoli("E-mail musi zawierać @");
                        }
                    }
                } while(malpa == string::npos);
                string adres = pole("Adres", true, w.get_adres());
                ksiazka->zmien_wpis(numer, Wpis(imie, nazwisko, nf, tel, fax, email, adres));
                dokonsoli("Zmieniony wpis #" + to_string(numer+1));
            }    
        }
        
        if(komenda == "uw") {
            unsigned int numer = stoi(pole("Numer wpisu", false));
            if (numer < 1) {
                dokonsoli("Numer wpisu nie może być mniejszy niż 1");
                continue;
            }
            
            if (numer > ksiazka->liczba_wpisow()) {
                dokonsoli("Wpis #" + to_string(numer) + " nie istnieje");
                continue;
            }
            
            numer -= 1;
            dokonsoli("Usunąć: " + ksiazka->get_wpis(numer).drukuj_krotko());
            string tak = pole("Potwierdź z 'tak'", false);
            if (tak == "tak") {
                ksiazka->usun_wpis(numer);
                dokonsoli("Wpis usunięty");
            } else {
                dokonsoli("To nic");
            }
        }
        
        if(komenda == "lw") {
            dokonsoli("Lista wpisów:");
            int index = 1;
            string out;
            for(Wpis w: ksiazka->get_wpisy()) {
                out = to_string(index) + ") " + w.drukuj_krotko();
                dokonsoli(out);
                index++;
            }
        }
        
        if(komenda == "pw") {
            unsigned int numer = stoi(pole("Numer wpisu", false));
            if (numer < 1) {
                dokonsoli("Numer wpisu nie może być mniejszy niż 1");
                continue;
            }
            
            if (numer > ksiazka->liczba_wpisow()) {
                dokonsoli("Wpis #" + to_string(numer) + " nie istnieje");
                continue;
            }
            
            numer -= 1;
            dokonsoli(ksiazka->get_wpis(numer).drukuj_wszystko());
        }
        
        if(komenda == "op") {
            run = false;
        }
        
    } while (run);
    
    return 0;
}
