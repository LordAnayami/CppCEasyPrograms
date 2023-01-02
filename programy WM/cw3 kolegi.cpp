#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Macierz
{
    public:
        Macierz();
        Macierz(int dlugosc, double zamienna_macierz [3][3]);
        double get(int i, int j) //getter
        {
            cout << "\nWartosc [" << i << "][" << j << "] wynosi: " << mac[i][j] << "\n";
            return mac[i][j];
        };

        void set(int i, int j, int nowa_wartosc)
        {
            cout << "\nZmiana wartosci [" << i << "][" << j << "] na: " << nowa_wartosc << "\n";
            mac[i][j] = nowa_wartosc;
        }
        Macierz operator +(Macierz x);

        Macierz operator -(Macierz x);

        Macierz operator *(Macierz x);

        Macierz operator *(double x);

        Macierz operator ~();

        friend ostream & operator << (ostream &out, Macierz x);
        friend istream & operator >> (istream &in,  Macierz &x);

        double * operator()(int i, int j);

    private:
        int n = 3;
        double mac [3][3];
};

Macierz::Macierz()
{
    for(int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            memset(mac, 0, sizeof(mac));
        }
    }
};

Macierz::Macierz(int dlugosc, double nowa_macierz [3][3])
{
    n = dlugosc;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mac[i][j] = nowa_macierz[i][j];
        }
    }
};

Macierz Macierz::operator +(Macierz x)
{
        Macierz nowa_macierz;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nowa_macierz.mac[i][j]=mac[i][j]+x.mac[i][j];
            }
        }
        return nowa_macierz;
}

Macierz Macierz::operator -(Macierz x)
{
        Macierz nowa_macierz;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nowa_macierz.mac[i][j]=mac[i][j]-x.mac[i][j];
            }
        }
        return nowa_macierz;
}

Macierz Macierz::operator*(Macierz x)
{
        Macierz nowa_macierz;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nowa_macierz.mac[i][j]=mac[i][j]*x.mac[i][j];
            }
        }
        return nowa_macierz;
}

Macierz Macierz::operator*(double x)
{
        Macierz nowa_macierz;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nowa_macierz.mac[i][j]=mac[i][j]*x;
            }
        }
        return nowa_macierz;
}

Macierz Macierz::operator~()
{
    Macierz nowa_macierz;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            nowa_macierz.mac[j][i] = mac[i][j];
        }
    }
    return nowa_macierz;
}

ostream & operator<<(ostream &out, Macierz x)
{
    for(int i=0; i<x.n; i++)
    {
        for(int j=0; j<x.n; j++)
        {
            out<<x.mac[i][j]<<"\t";
        }
        out<<"\n";
    }
    return out;
}

istream & operator >> (istream &in, Macierz &x)
{
    cout << "Prosze wprowadzic wartosci matrycy.\n";
    for(int i=0; i<x.n; i++)
    {
        for(int j=0; j<x.n; j++)
        {
            cout << "Wartosc dla [" << i << "] [" << j << "]: \n";
            in >> x.mac[i][j];
        }
    }
    cout << "Wprowadzono wartosci.\n\n";
    return in;
}

double * Macierz::operator()(int i, int j)
{
    return &mac[i][j];
}

int main()
{
    cout << "Macierz stworzona przy pomocy konstruktora bezargumentowego:" << "\n";
    Macierz m1;
    cin >> m1;
    cout << m1;
    m1.set(2, 2, 128);
    cout << m1;
    cout << "Wartosc pola [2][2]:"<< m1.get(2, 2) << "\n";

    cout << "Dwie macierze stworzona przy pomocy konstruktora z argumentami" << "\n";
    double nowa_macierz2 [3][3] = {{0, 1, 2} ,{3, 4, 5}, {6, 7, 8}};;
    Macierz m2 (3, nowa_macierz2);
    cout << m2 << "\n";

    double nowa_macierz3 [3][3] = {{5, 3, 3} ,{6, 1, 2}, {9, 2, 1}};;
    Macierz m3 (3, nowa_macierz3);
    cout << m3;

    cout << "\nSuma macierzy: \n";
    Macierz suma_macierzy;
    suma_macierzy = m2 + m3;
    cout << suma_macierzy;

    cout << "\nRoznica macierzy: \n";
    Macierz roznica_macierzy;
    roznica_macierzy = m2 - m3;
    cout << roznica_macierzy;

    cout << "\nIloraz macierzy: \n";
    Macierz iloraz_macierzy;
    iloraz_macierzy = m2 * m3;
    cout << iloraz_macierzy;


    cout << "\nPierwsza macierz stworzona przy pomocy konstruktora z argumentami przemnorzona przez 2.5 : \n";
    Macierz przemnozona_macierz;
    przemnozona_macierz = m2 * (double)2.5;
    cout << przemnozona_macierz;

    cout << "\nTransponowanie pierwszej macierzy stworzonej przy pomocy konstruktora z argumentami : \n";
    Macierz transponowana_macierz;
    transponowana_macierz = ~m2;
    cout << transponowana_macierz;

    cout << "\nElement [0][0] i [1][2] z transponowanej macierzy: \n" << *transponowana_macierz(0, 0) << ", " << *transponowana_macierz(1, 2);
    cout << "\nZamiana elementu [1][1] z w.w. macierzy na 3: \n";
    *transponowana_macierz(1, 1) = 3;
    cout << transponowana_macierz;
};
