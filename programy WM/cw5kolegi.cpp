#include <iostream>
#include <new>
#include <stdio.h>
#include <string.h>

using namespace std;

template <class T> class Tablica
{
    public:
        Tablica()
        {
            n = 10;
            try
                {
                wsk = new T[n];
                delete [] wsk;
                cout << "Tablica zostala stworzona przy pomocy konstruktora bezargumentowego" << "\n";
                }
            catch(bad_alloc&e)
                {

                    cout<< "Wyjątek klasy bad_alloc" << endl;
                    e.what();
                }
        };

        Tablica(int dlugosc_listy)
        {
            n = dlugosc_listy;
            try
            {
                wsk = new T[n];
                delete [] wsk;
            }
            catch(bad_alloc&e)
            {

                cout<< "Wyjątek klasy bad_alloc" << endl;
                e.what();
            }
            cout << "Tablica zostala stworzona przy pomocy konstruktora z argumentem" << "\n";
        };

        Tablica(const Tablica &t)
        {
            n = t.n;
            wsk = new T[n];
            try
            {
                for (int i = 0; i <= n; i++)
                    wsk[i] = t.wsk[i];
            }
            catch(bad_alloc&e)
            {

                cout<< "Wyjątek klasy bad_alloc" << endl;
                e.what();
            }
            cout << "Tablica zostala stworzona przy pomocy konstruktora z argumentem" << "\n";
            cout << "Tablica zostala skopiowana" << "\n";
        };
        ~Tablica()
        {
            delete [] wsk;
            cout <<  "Tablica zostala zniszczona. \n\n";
        };

        int get(int i) //getter
        {
            return wsk[i-1];
        };
        void set(int i, int nowa_wartosc) //setter
        {
            wsk[i-1] = nowa_wartosc;
        };

        void wypisz()
        {
            for (int i = 0; i < n; i++)
                cout << wsk[i] << " ";
            cout << "\n";
        };
        int minimum()
        {
            int najmniejszy = 10;
            for (int i = 0; i < n; i++)
            {
                if (wsk[i] <= najmniejszy)
                    najmniejszy = wsk[i];
            }
            return najmniejszy;
        };
        int maksimum()
        {
            int najwiekszy = 0;
            for (int i = 0; i < n; i++)
            {
                if (wsk[i] >= najwiekszy)
                    najwiekszy = wsk[i];
            }
            return najwiekszy;
        };
        ostream & operator << (ostream &out)
        {
            for(int i=0; i<wsk.n; i++)
            {
                out<<wsk[i]<<"\t";
            }
            out<<"\n";
            return out;
        }

        istream & operator >> (istream &in, T &x)
        {
            cout << "Prosze wprowadzic wartosci matrycy.\n";
            for(int i=0; i<x.n; i++)
            {
                cout << "Prosze podac wartosc dla [" << i << "]: \n";
                in >> x[i];
            }
            cout << "Wprowadzono wartosci.\n\n";
            return in;
        }

        operator [ ] (int index, int zmienna_do_wlozenia)
        {
            if (zmienna_do_wlozenia == NULL):
                wsk[i] = zmienna_do_wlozenia;
            return wsk[i]
        }
    private:
        int n;
        int *wsk;
}

ostream & operator << (ostream &out, T x);
{
    for(int i=0; i<x.n; i++)
    {
        out<<x[i]<<"\t";
    }
    out<<"\n";
    return out;
}
istream & operator >> (istream &in, T &x)
        {
            cout << "Prosze wprowadzic wartosci matrycy.\n";
            for(int i=0; i<x.n; i++)
            {
                cout << "Prosze podac wartosc dla [" << i << "]: \n";
                in >> x[i];
            }
            cout << "Wprowadzono wartosci.\n\n";
            return in;
        }
int main()
{
    tablica1 <float> = new Tablica(5);
    cin >> tablica1;
    cout >> tablica1;
}

