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
   cout << "Utworzono obiekt konstruktorem bezargumentowym" << endl;
}

prostokat::prostokat(float s, float w)
{
   szer = s;
   wys = w;
   cout << "Utworzono obiekt konstruktorem z argumentami" << endl;
}

prostokat::~prostokat()
{
   // destruktor taki jak domyœlny - funkcja pusta w œrodku
   cout << "Zniszczono obiekt" << endl;
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
   
   prostokat p1;       // konstruktor bezargumentowy
   prostokat p2(2, 3); // konstruktor z argumentami
   
   // dynamiczne tworzenie obiektu:
   prostokat *wsk = new prostokat(3, 4); // konstruktor z argumentami
   
   {
      prostokat p3; // konstruktor bezargumentowy
   } // tutaj koniec zakresu widocznoœci obiektu p3

   p1.prostokat::~prostokat(); // uruchomienie destruktora dla obiektu p1
   delete wsk; // dynamiczne usuniêcie obiektu wskazywanego przez wsk
   
   system("pause");
   return 0;
} // tutaj koniec zakresu widocznoœci obiektów p1, p2
