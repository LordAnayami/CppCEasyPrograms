// Æwiczenie 5 - Funkcje operatorowe
// Klasa Macierz - programowy model statycznej tablicy dwuwymiarowej
// o rozmiarze 3x3 (macierz kwadratowa) dla liczb zmiennoprzecinkowych
// (C)2020 Robert Arsoba

#include <iostream> // cout, istream, ostream
#include <iomanip>  // setw
#include <cstdlib>  // exit, system
using namespace std;
#define N 3

// deklaracja klasy Macierz
class Macierz
{
   public:
      Macierz(); // konstruktor bezargumentowy
      Macierz(int rozmiar, float m[][N]); // konstruktor z argumentami
      //----- funkcje udostêpniaj¹ce (getter i setter) -----
      float get(int i, int j) { return mac[i][j]; }      // getter - zwraca pole prywatne
      void set(int i, int j, float x) { mac[i][j] = x; } // setter - ustawia pole prywatne
      //----- funkcje operatorowe sk³adowe -----
      Macierz operator+(Macierz m);
      Macierz operator-(Macierz m);
      Macierz operator*(Macierz m);
      Macierz operator~(); // transpozycja macierzy
      float &operator()(int i, int j);
      //----- funkcje operatorowe zaprzyjaŸnione -----      
      friend Macierz operator*(float x, Macierz m);
      friend ostream& operator<<(ostream &os, Macierz m);
      friend istream& operator>>(istream &is, Macierz &m);
   private:
      int n;           // rozmiar macierzy kwadratowej
      float mac[N][N]; // zawartoœæ macierzy
};

Macierz::Macierz()
{
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         mac[i][j] = 0.0;
}

Macierz::Macierz(int rozmiar, float m[][N])
{
   if (rozmiar != N)
   {
      cout << "Nieprawidlowy rozmiar tablicy" << endl;
      exit(-1);
   }
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         mac[i][j] = m[i][j];
}

Macierz Macierz::operator+(Macierz m)
{
   Macierz wynik;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         wynik.mac[i][j] = mac[i][j]+m.mac[i][j];
   return wynik;
}

Macierz Macierz::operator-(Macierz m)
{
   Macierz wynik;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         wynik.mac[i][j] = mac[i][j]-m.mac[i][j];
   return wynik;   
}

Macierz Macierz::operator*(Macierz m)
{
   Macierz wynik;
   float s;
   for(int i = 0; i < N; i++)
      for(int j = 0; j < N; j++)
      {
         s = 0.0;
         for(int k = 0; k < N; k++)
            s += mac[i][k]*m.mac[k][j];
         wynik.mac[i][j] = s;
      }   
   return wynik;
}

Macierz Macierz::operator~()
{
   Macierz wynik;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         wynik.mac[i][j] = mac[j][i];
   return wynik;      
}

float &Macierz::operator()(int i, int j)
{
   return mac[i][j];
}

Macierz operator*(float x, Macierz m)
{
   Macierz wynik;
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
         wynik.mac[i][j] = x*m.mac[i][j];
   return wynik;         
}

ostream& operator<<(ostream &os, Macierz m)
{
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
         os << setw(7) << m.mac[i][j];
      os << endl;
   }
   return os;
}

istream& operator>>(istream &is, Macierz &m)
{
   for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
      {
         cout << "Podaj element " << '[' << i << "][" << j << "] = ";
         is >> m.mac[i][j];
      }
   return is;   
}

int main()
{
   system("cls");
   
   float tab1[3][3] =
   {
      { 1, 1, 1 },
      { 1, 1, 1 },
      { 1, 1, 1 }      
   };

   float tab2[3][3] =
   {
      { 2, 2, 2 },
      { 2, 2, 2 },
      { 2, 2, 2 }      
   };
   
   Macierz m1(3, tab1), m2(3, tab2), m3;
   //cin >> m1;
   cin >> m2;
   cout << m1 << endl;
   cout << m2 << endl;
   m3 = m1+m2; cout << "Suma:"          << endl << m3 << endl;
   m3 = m1-m2; cout << "Roznica:"       << endl << m3 << endl;
   m3 = m1*m2; cout << "Iloczyn:"       << endl << m3 << endl;
   m3 = 2*m2;  cout << 2 << "*macierz:" << endl << m3 << endl;
   m3 = ~m1;   cout << "Transpozycja:"  << endl << m3 << endl;
   cout << m3(0, 0) << endl;
      
   system("pause");
   return 0;
}
