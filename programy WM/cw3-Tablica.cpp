// Æwiczenie 3 - Konstruktor kopiuj¹cy
// Klasa Tablica - programowy model dynamicznej tablicy jednowymiarowej
// dla liczb sta³oprzecinkowych
// (C)2020 Robert Arsoba

#include <iostream> // cout
#include <iomanip>  // setprecision
#include <cstdlib>  // system
#include <cmath>    // pow
using namespace std;

// deklaracja klasy Tablica
class Tablica
{
   public:
      Tablica();                 // konstruktor bezargumentowy
      Tablica(int rozmiar);      // konstruktor z argumentem
      Tablica(const Tablica &t); // konstruktor kopiuj¹cy
      ~Tablica();                // destruktor
      //----- funkcje udostêpniaj¹ce (getter i setter) -----
      int get(int i) { return wsk[i]; }    // getter - zwraca pole prywatne
      void set(int i, int x) { wsk[i] = x; } // setter - ustawia pole prywatne
      void losuj();   // losowanie zawartoœci tablicy z przedzia³u od 1 do 10
      void wypisz();  // wypisanie zawartoœci tablicy na ekranie
      float avg();    // œrednia arytmetyczna elementów tablicy
      float geom();   // œrednia geometryczna elementów tablicy
      int minimum();  // najmniejszy element tablicy
      int maksimum(); // najwiêkszy element tablicy
      void sortuj();  // sortowanie elementów tablicy
      int mediana();  // mediana
   private:
      int n;    // liczba elementów tablicy
      int *wsk; // adres tablicy dynamicznej
};

// definicja klasy Tablica

Tablica::Tablica()
{
   n = 10;
   try
   {
      wsk = new int[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;   
   }
   for (int i = 0; i < n; i++)
      wsk[i] = 0;
}

Tablica::Tablica(int rozmiar)
{
   n = rozmiar;
   try
   {
      wsk = new int[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;   
   }
   for (int i = 0; i < n; i++)
      wsk[i] = 0;
}

Tablica::Tablica(const Tablica &t)
{
   n = t.n;
   try
   {
      wsk = new int[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;
   }
   for (int i = 0; i < n; i++)
      wsk[i] = t.wsk[i];
}

Tablica::~Tablica()
{
   delete [] wsk;
}

void Tablica::losuj()
{
   srand(time(NULL));
   for (int i = 0; i < n; i++)
      wsk[i] = rand()%10+1; // zakres losowania od 1 do 10
}

void Tablica::wypisz()
{
   for (int i = 0; i < n; i++)
      cout << wsk[i] << ", ";
   cout << endl;
}

float Tablica::avg()
{
   int suma = 0;  
   for (int i = 0; i < n; i++)
      suma += wsk[i];
   return (float)suma/n;
}

float Tablica::geom()
{
   int iloczyn = 1;  
   for (int i = 0; i < n; i++)
      iloczyn *= wsk[i];
   return pow(iloczyn, 1.0/n);   
}

int Tablica::minimum()
{
   int wynik = wsk[0];
   for (int i = 1; i < n; i++)
      if (wsk[i] < wynik)
         wynik = wsk[i];
   return wynik;
}

int Tablica::maksimum()
{
   int wynik = wsk[0];
   for (int i = 1; i < n; i++)
      if (wsk[i] > wynik)
         wynik = wsk[i];
   return wynik;   
}

void Tablica::sortuj()
{
   // sortowanie b¹belkowe (bubble sort)
   for (int i = 0; i < n; i++)
      for (int j = 0; j < n-1; j++)
         if (wsk[j] > wsk[j+1]) // sortowanie rosn¹co
         {
            // zamiana miejscami swap(wsk[j], wsk[j+1]);
            int x;
            x = wsk[j];
            wsk[j] = wsk[j+1];
            wsk[j+1] = x;            
         }  
}

int Tablica::mediana()
{
   sortuj();
   return wsk[n/2]; // uproszczony wzór   
}

int main()
{
   system("cls");

   Tablica t(3);
   t.losuj();
   t.wypisz();
   t.set(0, 5);
   t.wypisz();
   cout << setprecision(2) << setiosflags(ios::fixed);
   cout << "pierwszy element     = " << t.get(0) << endl;
   cout << "srednia arytmetyczna = " << t.avg() << endl;
   cout << "srednia geometryczna = " << t.geom() << endl;
   cout << "najmniejszy element  = " << t.minimum() << endl;
   cout << "najwiekszy element   = " << t.maksimum() << endl;
   t.sortuj();
   t.wypisz();
   cout << "mediana              = " << t.mediana() << endl;

   Tablica kopia = t; // inicjalizacja za pomoc¹ konstruktora kopiuj¹cego
   kopia.Tablica::~Tablica(); // "rêczne" uruchomienie destruktora
      
   system("pause");
   return 0;
}
