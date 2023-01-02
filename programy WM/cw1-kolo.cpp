// Æwiczenie 1 - Wprowadzenie i podstawy (zajêcia przeprowadzone na uczelni)
// Klasa kolo - programowy model figury geometrycznej
// (C)2020 Robert Arsoba

#include <iostream> // cout
#include <cstdlib>  // system
using namespace std;

class kolo
{
   public:
      kolo();              // konstruktor bezargumentowy
      kolo(float promien); // konstruktor z argumentem
      //----- funkcje udostêpniaj¹ce (getter i setter) -----
      float getPromien() { return r; } // getter - zwraca pole prywatne
      void setPromien(float promien) { r = promien; } // setter - ustawia pole prywatne
      float obliczPole();
      float obliczObwod();
   private:
      float r; // promieñ ko³a
};

// konstruktor bezargumentowy (tworzy obiekt i ustawia pole r na 1)
kolo::kolo()
{
   r = 1.0;
}

// konstruktor z argumentem (tworzy obiekt i ustawia pole r na argument)
kolo::kolo(float promien)
{
   r = promien;
}

// funkcja skladowa zwraca pole powierzchni ko³a
float kolo::obliczPole()
{
   return 3.14*r*r;
}

// funkcja sk³adowa zwraca obwód ko³a
float kolo::obliczObwod()
{
   return 2*3.14*r;
}

int main()
{
   system("cls");
   
   kolo k1; // obiekt tworzony statycznie (posiada nazwê)
   // funkcje sk³adowe uruchamiane operatorem kropka
   cout << "Pole  = " << k1.obliczPole() << endl;
   cout << "Obwod = " << k1.obliczObwod() << endl;
   //----- niepoprawne operacje (pole r jest prywatne) -----
   // cout << "Promien kola = " << k1.r << endl;
   // k1.r = 2;
   //----- prawid³owe operacje to u¿ycie funkcji udostêpniaj¹cych -----
   cout << "Promien kola = " << k1.getPromien() << endl; // u¿ycie gettera
   k1.setPromien(2); // u¿ycie settera

   kolo *wsk;
   wsk = new kolo(1.0); // obiekt tworzony dynamicznie (przy pomocy wskaŸnika)
   // funkcje sk³adowe uruchamiane operatorem strza³ka
   cout << "Pole  = " << wsk->obliczPole() << endl;
   cout << "Obwod = " << wsk->obliczObwod() << endl;
   delete wsk; // tutaj niszczony jest obiekt wskazywany przez wskaŸnik wsk

   system("pause");
   return 0;
} // tutaj niszczony jest obiekt k1
