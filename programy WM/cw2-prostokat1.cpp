// Æwiczenie 2 - Tworzenie klas i obiektów
// Klasa prostokat - programowy model figury geometrycznej
// (C)2020 Robert Arsoba

#include <iostream> // cout
#include <cstdlib>  // system
using namespace std;

// deklaracja klasy prostokat
class prostokat
{
   public:
      prostokat();                 // konstruktor bezargumentowy
      prostokat(float s, float w); // konstruktor z argumentami
      ~prostokat();                // destruktor
      //----- funkcje udostêpniaj¹ce (getter i setter) -----
      float getSzer() { return szer; } // getter - zwraca pole prywatne
      float getWys()  { return wys; }
      void setSzer(float s) { szer = s; } // setter - ustawia pole prywatne
      void setWys(float w)  { wys = w; }
      float obliczPole();
      float obliczObwod();
   private:
      float szer; // szerokoœæ prostok¹ta
      float wys;  // wysokoœæ protok¹ta
};

// definicja klasy prostokat

prostokat::prostokat()
{
   szer = 1.0;
   wys = 1.0;
}

prostokat::prostokat(float s, float w)
{
   szer = s;
   wys = w;
}

prostokat::~prostokat()
{
   // destruktor taki jak domyœlny - funkcja pusta w œrodku
}

float prostokat::obliczPole()
{
   return szer*wys;
}

float prostokat::obliczObwod()
{
   return 2*(szer+wys);   
}

int main()
{
   system("cls");

   prostokat p;
   p.setSzer(2.0);
   p.setWys(3.0);
   cout << "Prostokat o bokach " << p.getSzer() << " i " << p.getWys() << endl;
   cout << "Pole prostokata  = " << p.obliczPole() << endl;
   cout << "Obwod prostokata = " << p.obliczObwod() << endl;
   
   prostokat *wsk;
   wsk = new prostokat(4, 5);
   cout << "Prostokat o bokach " << wsk->getSzer() << " i " << wsk->getWys() << endl;
   cout << "Pole powierzchni = " << wsk->obliczPole() << endl;
   delete wsk;
      
   system("pause");
   return 0;
}
