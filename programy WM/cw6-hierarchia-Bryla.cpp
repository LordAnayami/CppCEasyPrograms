// Æwiczenie 6 - Dziedziczenie i polimorfizm
// Hierarchia klas Bryla, Walec, Stozek, StozekSciety (programowe modele bry³)
// (C)2020 Robert Arsoba

#include <iostream> // cout
#include <cstdlib>  // system
using namespace std;

// klasa bazowa, abstrakcyjna
class Bryla
{
   public:
      Bryla(double rr, double hh) { r = rr; h = hh; }
      virtual ~Bryla() { } // destruktor wirtualny
      virtual void wypiszInfo() = 0;       // czysta funkcja wirtualna
      virtual double obliczObjetosc() = 0; // czysta funkcja wirtualna
   protected:
      double r; // promieñ podstawy
      double h; // wysokoœæ
      static const double PI; // sta³a matematyczna PI      
};

const double Bryla::PI = 3.14; // inicjalizacja pola statycznego

// klasa pochodna
class Walec : public Bryla
{
   public:
      Walec(double rr, double hh) : Bryla(rr, hh) { }
      ~Walec() { }
      virtual void wypiszInfo();
      virtual double obliczObjetosc() { return PI*r*r*h; }            
};

void Walec::wypiszInfo()
{
   cout << "Walec: " << "r = " << r << ", h = " << h << endl;   
}

// klasa pochodna
class Stozek : public Bryla
{
   public:
      Stozek(double rr, double hh) : Bryla(rr, hh) { }
      ~Stozek() { }
      virtual void wypiszInfo();
      virtual double obliczObjetosc() { return 1.0/3.0*PI*r*r*h; }    
};

void Stozek::wypiszInfo()
{
   cout << "Stozek: " << "r = " << r << ", h = " << h << endl;   
}

// klasa pochodna
class StozekSciety : public Stozek
{
   public:
      StozekSciety(double rr, double hh, double RR) : Stozek(rr, hh) { R = RR; }
      ~StozekSciety() { }
      virtual void wypiszInfo();
      virtual double obliczObjetosc() { return 1.0/3.0*PI*h*(r*r + r*R + R*R); }      
   private:
      double R; // promieñ œciêtej czêœci sto¿ka
};

void StozekSciety::wypiszInfo()
{
   cout << "Stozek sciety: ";
   cout << "r = " << r << ", h = " << h << ", R = " << R << endl; 
}

int main()
{
   system("cls");
   
   #define N 4
   Bryla *scena[N];
   scena[0] = new Walec(1, 1);
   scena[1] = new Stozek(1, 1);
   scena[2] = new StozekSciety(1, 1, 1);
   scena[3] = new Walec(1, 2);

   for (int i = 0; i < N; i++)
   {
      scena[i]->wypiszInfo();
      cout << "objetosc = " << scena[i]->obliczObjetosc() << endl;
   }
   
   for (int i = 0; i < N; i++)
      delete scena[i];

   system("pause");
   return 0;
}
