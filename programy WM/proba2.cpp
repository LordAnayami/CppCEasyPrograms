#include <iostream> //cout, sin
#include <cstdlib> //system
#include <time.h> //time
#include <math.h> //matematyczne funkcje
#include <cmath> //dla pow

using namespace std;


class Tablica //deklaracja tablicy
{
public:
    Tablica();
    int A[];
    int rozmiar;
    Tablica(int rozmiar); //deklaracja tablicy i rozmiaru
    ~Tablica(); //destruktor
    Tablicaspr();

    float Losuj();
    float Wypisz();
    float avg();
    float geom();
    float minimum();
    float maximum();
    float sortuj();
    float mediana();

    Tablica(const Tablica &t); //konstruktor kopiujacy o "zmiennie" t
    int geti(int i) {return A[i];} //gettter zwracaj¹cy wartosc elementu
    void seti (int i, int *wks) //setter dla wartosci argumentu
                        {
                            A[i]=*wsk;
                        }

private:
    int n; //rozmiar tablicy
    int *wsk;

};



Tablica::Tablicaspr() //sprawdzenie poprawnosci przydzialu pamieci
{

    wsk = new int[rozmiar];
    cout << "Sprawdzono poprawnosc" << endl;
}


Tablica::Tablica()  //konst bezargument
{
    n=10;
    A[n];
    for (int i = 0; i<n; i++)
        {
            A[i] = 0;

        }
    cout<< "Utworzono obiekt konstr bezargumentowym" <<endl;
}

Tablica::Tablica(int rozmiar)  //konst argument
{

    A[rozmiar];
    for (int i = 0; i<rozmiar; i++)
        {
            A[i] = 0;

        }

    cout<< "Utworzono obiekt konstr z argumentowym" <<endl;
}




Tablica::~Tablica() //funkcja destruktora
{
    delete [] wsk;
}

Tablica::Tablica(const Tablica &t)  //deklaracja konstruktora kopiuj¹cego
{
    rozmiar= t.rozmiar;
    wsk = new int[rozmiar];
    for (int i = 0; i<rozmiar; i++)
        wsk[i] = t.wsk[i];
}


float Tablica::Losuj()
{
    int i;
    srand(time(NULL)); /*bez tego losowanie s1 ci1gle te same liczby*/
    for ( i=0; i<=rozmiar-1; i++ )
    {
        A[i]=rand()%10+1; /*przedzial losowania 1..10*/
        cout << ("wylosowano %d \n", A[i]) <<endl;
    }
}

float Tablica::Wypisz()
{
    int i;
    cout << endl;
    for (i=0; i<=rozmiar-1; i++)
    {
        cout << (A[i]) <<endl;
    }
    cout << ("Koniec wypisywania") <<endl;
}

float Tablica::avg()
{
    int i;
    int suma;
   for (i=0; i<=rozmiar-1; i++)
    {
        suma=suma+A[i];
    }
    return suma/rozmiar;

}

float Tablica::geom()
{
    int i;
    int suma2;
    int wynik;
   for (i=0; i<=rozmiar-1; i++)
    {

        suma2=suma2*A[i];
    }

        wynik = pow(suma2, rozmiar);
    return wynik;

}

float Tablica::minimum()
{
    int i;
    int mini;
    for (i=0; i<=rozmiar-1; i++)
    {

        if (A[i]<A[i+1])
        {
            mini=A[i];
        }
        else
            {mini=A[i+1];
            }
    }
        return mini;
}
float Tablica::maximum()
{
    int i;
    int maxi;
    for (i=0; i<=rozmiar-1; i++)
    {

        if (A[i]>A[i+1])
        {
            maxi=A[i];
        }
         else
            {
                maxi=A[i+1];
            }
    }
        return maxi;
}


float Tablica::sortuj()
{
   int i, j, a, b, c, d;
   c=rozmiar-1;
   d=rozmiar-1;
   for (i = 0; i<d; i++)
   {
       for (j = 0; j<c; j++)
            {
        if (A[j]>A[j+1])
        {
            a=A[j];
            b=A[j+1];
            A[j]=b;
            A[j+1]=a;
        }

   }
       d=d-1;
       }
}

float Tablica::mediana()
{
    int i;
    int med;
    for (i=0; i<=rozmiar-1; i++)
    {

            med+=A[i];
        }

        return med/rozmiar;
}



int main()
{
    system ("clc");
    int n;
    Tablica t1;
    Tablica t2(15);

    t1.Wypisz();
    t2.Wypisz();

    t1.Losuj();
    t2.Losuj();

    t1.Wypisz();
    t2.Wypisz();

    t1.avg();
    t2.geom();

    t1.minimum();
    t2.maximum();

    t1.sortuj();
    t2.mediana();

    Tablica t3;
    t3=t1;


    system("pause");
    return 0;
}
