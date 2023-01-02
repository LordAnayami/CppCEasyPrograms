// Æwiczenie 7 - Szablony
// Szablon klasy Tablica - programowy model jednowymiarowej tablicy dynamicznej
// dla elementów dowolnego typu
// (C)2020 Robert Arsoba

#include <iostream>  // cout, istream, ostream
#include <cstdlib>   // system
#include <string>    // klasa string
using namespace std;

//--------------------------------------------------------------------------
template <class T> class Tablica; // deklaracja zapowiadaj¹ca szablonu klasy
// (wymagana dla operatorów poni¿ej)
// deklaracje zapowiadaj¹ce funkcji zaprzyjaŸnionych
template <class T> ostream& operator<< (ostream &os, Tablica<T> t);
template <class T> istream& operator>> (istream &is, Tablica<T> &t);
//--------------------------------------------------------------------------

template <class T> class Tablica
{
   public:
      Tablica();            // konstruktor bezargumentowy
      Tablica(int rozmiar); // konstruktor z argumentem
      Tablica(const Tablica<T> &t); // konstruktor kopiuj¹cy
      ~Tablica();           // destruktor
      T get(int i);         // getter
      void set(int i, T x); // setter
      void wypisz(); // wypisanie zawartoœci tablicy na ekranie
      T minimum();   // najmniejszy element tablicy
      T maksimum();  // najwiêkszy element tablicy
      //----- funkcje operatorowe -----
      T& operator[](int i); // indeksowanie tablicy
      friend ostream& operator<< <>(ostream &os, Tablica<T> t);  // wypisanie na ekranie
      friend istream& operator>> <>(istream &is, Tablica<T> &t); // odczyt z klawiatury
   private:
      int n;  // liczba elementów tablicy
      T *wsk; // adres tablicy dynamicznej (typ elementów to parametr szablonu)
};

template <class T> Tablica<T>::Tablica()
{
   n = 10;
   try
   {
      wsk = new T[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;   
   }
}

template <class T> Tablica<T>::Tablica(int rozmiar)
{
   n = rozmiar;
   try
   {
      wsk = new T[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;   
   }
   // zerowanie nie ma sensu: wsk[i] = 0;
}

template <class T> Tablica<T>::Tablica(const Tablica<T> &t)
{
   n = t.n;
   try
   {
      wsk = new T[n];
   }
   catch (bad_alloc &e)
   {
      cout << "Blad alokacji pamieci" << endl;
      cout << e.what() << endl;   
   }
   for (int i = 0; i < n; i++)
      wsk[i] = t.wsk[i];
}

template <class T> Tablica<T>::~Tablica()
{
   delete [] wsk;
}

template <class T> T Tablica<T>::get(int i)
{
   return wsk[i];   
}

template <class T> void Tablica<T>::set(int i, T x)
{
   wsk[i] = x;
}

template <class T> void Tablica<T>::wypisz()
{
   for (int i = 0; i < n; i++)
      cout << wsk[i] << ", ";
   cout << endl;
}

template <class T> T Tablica<T>::minimum()
{
   T wynik = wsk[0];
   for (int i = 1; i < n; i++)
      if (wsk[i] < wynik)
         wynik = wsk[i];
   return wynik;
}

template <class T> T Tablica<T>::maksimum()
{
   T wynik = wsk[0];
   for (int i = 1; i < n; i++)
      if (wsk[i] > wynik)
         wynik = wsk[i];
   return wynik;   
}

template <class T> T& Tablica<T>::operator[](int i)
{
   return wsk[i];   
}

template <class T> ostream& operator<< (ostream &os, Tablica<T> t)
{
   for (int i = 0; i < t.n; i++)
      os << t.wsk[i] << ", ";
   os << endl;
   return os;   
}

template <class T> istream& operator>> (istream &is, Tablica<T> &t)
{
   for (int i = 0; i < t.n; i++)
   {
      cout << "Podaj element " << i << " = "; 
      is >> t.wsk[i];
   }
   return is;
}

int main()
{
   system("cls");
   
   Tablica<int> liczby(3); // konkretyzacja szablonu dla typu int
   liczby[0] = 5;
   liczby[1] = 3;
   liczby[2] = 7;
   //cin >> liczby;
   liczby.wypisz();
   cout << "piersza    : " << liczby.get(0) << endl;
   cout << "najmniejsza: " << liczby.minimum() << endl;
   cout << "najwieksza : " << liczby.maksimum() << endl;
      
   Tablica<string> napisy(3); // konkretyzacja szablonu dla typu string
   napisy[0] = "Ala";
   napisy[1] = "Ula";
   napisy[2] = "Ola";
   cout << napisy;
   cout << "pierszy    : " << napisy[0] << endl;
   cout << "najmniejszy: " << napisy.minimum() << endl;
   cout << "najwiekszy : " << napisy.maksimum() << endl;
   
   system("pause");
   return 0;
}
