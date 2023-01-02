// Æwiczenie 4 - Funkcje zaprzyjaŸnione
// Klasa Konto - programowy model konta bankowego (wykorzystuje klasê Osoba)
// Klasa Osoba - programowy model osoby (podstawowe dane osobowe)
// (C)2020 Robert Arsoba

#include <iostream> // cout
#include <cstdlib>  // system
#include <string>   // klasa string
using namespace std;

class Osoba
{
   public:
      Osoba(string _imie, string _nazwisko) { imie = _imie; nazwisko = _nazwisko; }
      string getImie() { return imie; } // getter
      string getNazwisko() { return nazwisko; } // getter
   private:
      string imie;     // imiê osoby
      string nazwisko; // nazwisko osoby
};

class Konto
{
   public:
      Konto(Osoba os);
      float getSaldo() { return saldo; } // getter
      void setSaldo(float kwota) { saldo = kwota; } // setter
      //----- funkcje zaprzyjaŸnione -----
      friend void wypisz(Konto k);
      friend void wplata(Konto &k, float kwota);
      friend void wyplata(Konto &k, float kwota);
      friend void przelew(Konto &k1, Konto &k2, float kwota);
   private:
      Osoba klient; // dane osobowe w³aœciciela konta
      float saldo;  // aktualny stan konta (kwota pieniêdzy na koncie)
};

Konto::Konto(Osoba os) : klient(os)
{
   saldo = 0.0;
}

void wypisz(Konto k)
{
   cout << "imie    : " << k.klient.getImie() << endl;
   cout << "nazwisko: " << k.klient.getNazwisko() << endl;
   cout << "saldo   : " << k.saldo << endl; // lub k.getSaldo()
}

void wplata(Konto &k, float kwota)
{
   k.saldo += kwota;   
}

void wyplata(Konto &k, float kwota)
{
   if (k.saldo < kwota)
      cout << "Wyplata niemozliwa do wykonania" << endl;   
   else
      k.saldo -= kwota;
}

void przelew(Konto &k1, Konto &k2, float kwota)
{
   if (k1.saldo < kwota)
      cout << "Przelew niemozliwy do wykonania" << endl;   
   else
   {   
      k1.saldo -= kwota;   
      k2.saldo += kwota;   
   }
}

int main()
{
   system("cls");

   Osoba os1("Jan", "Kowalski");
   Osoba os2("Jerzy", "Nowak");
   
   Konto konto1(os1), konto2(os2);
   wypisz(konto1);
   wypisz(konto2);
   wplata(konto1, 100); cout << "saldo = " << konto1.getSaldo() << endl;
   wyplata(konto1, 20); cout << "saldo = " << konto1.getSaldo() << endl;
   przelew(konto1, konto2, 10);
   cout << "saldo = " << konto1.getSaldo() << endl;
   cout << "saldo = " << konto2.getSaldo() << endl;
   
   Konto *rach1, *rach2;
   rach1 = new Konto(os1);
   rach2 = new Konto(os2);
   wypisz(*rach1);
   wypisz(*rach2);
   wplata(*rach1, 100); cout << "saldo = " << rach1->getSaldo() << endl;
   wyplata(*rach1, 20); cout << "saldo = " << rach1->getSaldo() << endl;
   przelew(*rach1, *rach2, 10);
   cout << "saldo = " << rach1->getSaldo() << endl;   
   cout << "saldo = " << rach2->getSaldo() << endl;   
   delete rach1;
   delete rach2;
   
   system("pause");
   return 0;
}
