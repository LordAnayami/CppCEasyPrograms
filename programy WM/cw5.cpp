#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

#include <new> // bad_alloc

using namespace std;

template<class wsk> class Tablica
{
public:
    Tablica(int n = 10); // konstruktor bezwarunkowy 1
    ~Tablica(); // destruktor
    wsk& operator [] (int n); // operator indeksowania
    friend ostream & operator << (ostream &out, int n);
    friend istream & operator >> (istream &in, int n);
private:
    wsk* t; // wskaźnik na tablicę danych typu T
    int rozmiar; // rozmiar tablicy (liczba elementów)

};

// konstruktor warunkowy 2
template <class wsk> Tablica<wsk>::Tablica(int n)
{
    rozmiar = n;
    t = new wsk[rozmiar]; // tablica danych typu T}
// należy sprawdzić przydział pamięci!
}

//kopiująca 3
template <class wsk> Tablica <wsk>::Tablica(const Tablica &t)
    {
        n = t.n;
        wsk = new int[n];
        for (int i = 0; i < n; i++)
        wsk[i] = t.wsk[i];
    }


// destruktor 4
template <class wsk> Tablica<wsk>::~Tablica()
{
    delete t[];
}

//getter 5
int get(int i)
		{
			return wsk[i];
		}


//setter 6
void set(int i, int j)
		{
			wsk[i]=j;
		}

// wypisz 7
void wypisz( int n)
		{
			for(int i=0;i<n;i++)
			cout << wsk[i] << " ";
		}


// funkcja min 8
template <class wsk> wsk min (int n )
{
    int temp=wsk[0];
    for(int i=0;i<n;i++)
            if(wsk[i]<temp)
            temp=wsk[i];

    return temp;
    }



// funkcja max 9
template <class wsk> wsk max (int n )
{
    int temp=wsk[0];
    for(int i=0;i<n;i++)
            if(wsk[i]>temp)
            temp=wsk[i];

    return temp;
    }


// operator indeksowania
template <class wsk> wsk& Tablica<wsk>::operator [] (int i, int j)
{
    wsk[i]=j;
    return wsk[i];
}


// operator <<
template <class wsk> wsk& Tablica<wsk>::ostream & operator << (osteam &out, wsk[n])
{
    for(int i=0;i<n;i++)
    {out << wsk[i] << " ";}
}


// operator >>
template <class wsk> wsk& Tablica<wsk>::insteam & operator >> (istream &in, wsk[n])
{
    for(int i=0;i<n;i++)
    {
        cout << "Podaj wartosc tablicy o numerze " << i <<endl;
        int >> wsk[i] >>endl;
    }
}


//bad allock
try
{
while (true)
wsk= new double[1000000];
}
catch(bad_alloc &e)
{
cout << "Wyjątek klasy bad_alloc" << endl;
e.what();
}

main()
{
    Tablica <int> tab10;
    cout >> tab10;


    Tablica *tab=new Tablica(15);
    cin << tab;

    if(tab->get(0) == 0 && tab10->get(0)==0) // sprawdzenie czy zerowa wartoœæ wskaznika wskazuje na pierwszy element wyzerowanej tablicy
		cout << "Przydzial pamieci poprawny!" << endl << endl;

	tab->set(5,3);
	cout << "6 element Tablicy 1: " << tab->get(5) << endl;

	tab->max;
	tab->min;

	tab [] (2,1);
	cout << "3 element Tablicy 1: " << tab->get(2) << endl;

	delete tab;
	delete tab10;
	return 0;
}
