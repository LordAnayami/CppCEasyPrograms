#include <iostream>
#include <iomanip>


/*
 *  Definicja ROZMIAR, okreslacja rozmiary macierzy
 */
#define ROZMIAR 3

/*
 *  Definicja zawartosci tablic TAB
 *  na potrzeby wywolania konstruktora obiektu z argumentami
 *  dla macierzy o rozmiarach 2x2, 3x3, 5x5
 *  okreslonych poprzez definicje ROZMIAR
 */
#if ROZMIAR == 2
#define TAB { {0.1,0.2},{0.3,0.4} }
#elif ROZMIAR == 3
#define TAB { {0.1,0.2,0.3},{0.4,0.5,0.6},{0.7,0.8,0.9} }
#elif ROZMIAR == 5
#define TAB { {0.1,0.2,0.3,0.4,0.5},{0.6,0.7,0.8,0.9,0.10},{0.11,0.12,0.13,0.14,0.15},{0.16,0.17,0.18,0.19,0.20},{0.21,0.22,0.23,0.24,0.25} }
#endif


class Macierz
{
private:
    int n;
    float mac[ROZMIAR][ROZMIAR];

public:
    Macierz();
    Macierz(int rozmiar, float tab[ROZMIAR][ROZMIAR]);
    float get(int i, int j)
    {
        return mac[i][j];
    }
    void set(int i, int j, float wartosc)
    {
        mac[i][j] = wartosc;
    }
    Macierz dodawanie(Macierz y);
    Macierz operator+ (Macierz y);
    Macierz odejmowanie(Macierz y);
    Macierz operator- (Macierz y);
    Macierz mnozenie(Macierz y);
    Macierz operator* (Macierz y);
    friend Macierz mnozenie(float wartosc, Macierz y);
    friend Macierz operator* (float wartosc, Macierz y);
    friend Macierz transponowanie(Macierz y);
    friend Macierz operator~(Macierz y);
    friend std::ostream& operator<< (std::ostream& os, Macierz x);
    friend std::istream& operator>> (std::istream& is, Macierz &x);
    float& operator() (int i, int j);
};

Macierz::Macierz()
{
    std::cout << "Tworzenie obiektu przy uzyciu konstruktora domyslnego" << std::endl;
    n = ROZMIAR;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mac[i][j] = 0;
        }
    }
}

Macierz::Macierz(int rozmiar, float tab[ROZMIAR][ROZMIAR])
{
    std::cout << "Tworzenie obiektu przy uzyciu konstruktora z argumentami" << std::endl;
    n = rozmiar;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mac[i][j] = tab[i][j];
        }
    }
}

Macierz Macierz::dodawanie(Macierz y)
{
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) + y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz Macierz::operator+ (Macierz y)
{
    std::cout << "Operator + :Dodaje elementy obiektu do elementow drugiego obiektu" << std::endl;
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) + y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz Macierz::odejmowanie(Macierz y)
{
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) - y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz Macierz::operator- (Macierz y)
{
    std::cout << "Operator - :Odejmuje elementy obiektu od elementow drugiego obiektu" << std::endl;
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) - y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz Macierz::mnozenie(Macierz y)
{
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) * y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz Macierz::operator* (Macierz y)
{
    std::cout << "Operator * :Mnoze elementy obiektu przez elementy drugiego obiektu" << std::endl;
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = this->get(i, j) * y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz mnozenie(float wartosc, Macierz y)
{
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = wartosc * y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz operator* (float wartosc, Macierz y)
{
    std::cout << "Operator * :Mnoze elementy obiektu przez wartosc" << std::endl;
    Macierz z;
    float nowa_wartosc;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            nowa_wartosc = wartosc * y.get(i, j);
            z.set(i, j, nowa_wartosc);
        }
    }
    return z;
}

Macierz transponowanie(Macierz y)
{
    Macierz z;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            z.set(i, j, y.get(j,i));
        }
    }
    return z;
}

Macierz operator~ (Macierz y)
{
    std::cout << "Operator ~ :Wyznaczam macierz transponowana" << std::endl;
    Macierz z;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            z.set(i, j, y.get(j,i));
        }
    }
    return z;
}

std::ostream& operator<< (std::ostream &os, Macierz x)
{
    std::cout << "Operator << :Wyswietlam elementy obiektu" << std::endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            os.width(10);
            os << std::setprecision(2) << std::fixed << x.get(i, j);
        }
        os << std::endl;
    }
    return os;
}

std::istream& operator>> (std::istream& is, Macierz &x)
{
    std::cout << "Operator >> :Wprowadz elementy obiektu:" << std::endl;
    for (int i = 0; i < ROZMIAR; i++)
    {
        for (int j = 0; j < ROZMIAR; j++)
        {
            float nowa_wartosc;
            is >> nowa_wartosc;
            x.set(i,j,nowa_wartosc);
        }
    }
    return is;
}

float& Macierz::operator() (int i, int j)
{
    std::cout << "Element o indeksie: (" << i << ", " << j << ")" << std::endl;
    return mac[i][j];
}


int main()
{
    Macierz m0;
    std::cout << "Obiekt m0:" << std::endl << m0 << std::endl;
    std::cout << "Obiekt m0: f.skladowa get(), Wyswietlam wartosc elementu o indeksie (1, 1)" << std::endl << m0.get(1, 1) << std::endl << std::endl;
    std::cout << "Obiekt m0: f.skladowa set(), Podmieniam wartosc elementu o indeksie (1, 1) na 1" << std::endl; m0.set(1, 1, 1); std::cout << std::endl;
    std::cout << "Obiekt m0:" << std::endl << m0 << std::endl;

    float tab1[ROZMIAR][ROZMIAR] = TAB;
    Macierz m1(ROZMIAR, tab1);
    std::cout << "Obiekt m1:" << std::endl << m1 << std::endl;

    Macierz m2;
    m2 = ~m1;
    std::cout << "Obiekt m2:" << std::endl << m2 << std::endl;

    Macierz m3;
    m3 = m1 + m2;
    std::cout << "Obiekt m3: //m3 = m1 + m2" << std::endl << m3 << std::endl;

    Macierz m4;
    m4 = m1 - m2;
    std::cout << "Obiekt m4: //m4 = m1 - m2" << std::endl << m4 << std::endl;

    Macierz m5;
    m5 = m1 * m2;
    std::cout << "Obiekt m5: //m5 = m1 * m2" << std::endl << m5 << std::endl;

    Macierz m6;
    m6 = 0.5 * m2;
    std::cout << "Obiekt m6: //m6 = 0.5 * m2" << std::endl << m6 << std::endl;

    Macierz m7;
    std::cin >> m7;
    std::cout <<"Obiekt m7:"<<std::endl << m7 << std::endl;

    std::cout << "Operator () jako setter: Podmieniam wartosc elementu o indeksie (1, 1) na 8543" << std::endl;
    m7(1, 1) = 8543;
    std::cout << std::endl;

    std::cout << "Operator () jako getter: Wyswietlam wartosc elementu o indeksie (1, 1)" << std::endl;
    float x;
    x = m7(1, 1);
    std::cout << std::setprecision(0) << x << std::endl;
    std::cout << std::endl;

    std::cout << "Obiekt m7:" << std::endl << m7 << std::endl;

    return 0;
}
