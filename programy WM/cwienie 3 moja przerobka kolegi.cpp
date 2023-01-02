#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Macierz
{
    public:
        Macierz();
        Macierz(int dlug, double zm_mac [3][3]);
        double get(int i, int j) //getter
        {
            cout << "\n Wartosc [" << i << "][" << j << "] wynosi: " << mac[i][j] << "\n";
            return mac[i][j];
        };

        void set(int i, int j, int nw_war)
        {
            cout << "\n Zmiana wartosci [" << i << "][" << j << "] na: " << nw_war << "\n";
            mac[i][j] = nw_war;
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

Macierz::Macierz(int dlug, double nw_mac [3][3])
{
    n = dlug;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            mac[i][j] = nw_mac[i][j];
        }
    }
};

Macierz Macierz::operator +(Macierz x)
{
        Macierz nw_mac;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nw_mac.mac[i][j]=mac[i][j]+x.mac[i][j];
            }
        }
        return nw_mac;
}

Macierz Macierz::operator -(Macierz x)
{
        Macierz nw_mac;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nw_mac.mac[i][j]=mac[i][j]-x.mac[i][j];
            }
        }
        return nw_mac;
}

Macierz Macierz::operator*(Macierz x)
{
        Macierz nw_mac;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nw_mac.mac[i][j]=mac[i][j]*x.mac[i][j];
            }
        }
        return nw_mac;
}

Macierz Macierz::operator*(double x)
{
        Macierz nw_mac;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                    nw_mac.mac[i][j]=mac[i][j]*x;
            }
        }
        return nw_mac;
}

Macierz Macierz::operator~()
{
    Macierz nw_mac;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            nw_mac.mac[j][i] = mac[i][j];
        }
    }
    return nw_mac;
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
    cout << "Prosze wprowadzic wartosci macierzy.\n";
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
    m1.set(1, 3, 14);
    cout << m1;
    cout << "Wartosc pola [1][3] wynosi:"<< m1.get(1, 3) << "\n";

    cout << "Druga macierz stworzona przy pomocy konstruktora z argumentami" << "\n";
    double nw_mac2 [3][3] = {{0, 10, 1} ,{4, 7, 5}, {7, 2, 6}};;
    Macierz m2 (3, nw_mac2);
    cout << m2 << "\n";

    double nw_mac3 [3][3] = {{7, 5, 2} ,{8, 4, 1}, {9, 6, 3}};;
    Macierz m3 (3, nw_mac3);
    cout << m3;

    cout << "\n Suma macierzy 1 i 2 : \n";
    Macierz suma_macierzy;
    suma_macierzy = m1 + m2;
    cout << suma_macierzy;

    cout << "\n Roznica macierzy 1 i 2 : \n";
    Macierz roznica_macierzy;
    roznica_macierzy = m1 - m2;
    cout << roznica_macierzy;

    cout << "\n Iloraz macierzy 1 i 2: \n";
    Macierz iloraz_macierzy;
    iloraz_macierzy = m1 * m2;
    cout << iloraz_macierzy;


    cout << "\n Pierwsza macierz przemnorzona przez 1.5 : \n";
    Macierz przem_mac;
    przem_mac = m1 * (double)1.5;
    cout << przem_mac;

    cout << "\n Transponowanie pierwszej macierzy : \n";
    Macierz trans_mac;
    trans_mac = ~m1;
    cout << trans_mac;

    cout << "\n Element [1][1] i [1][3] z transponowanej macierzy: \n" << *trans_mac(1, 1) << ", " << *trans_mac(1, 3);
    cout << "\n Zamiana elementu [1][1] z w.w. macierzy na 3: \n";
    trans_mac.set(1, 1, 3);
    cout << trans_mac;
};
