#include <iostream>
#include <stdio.h>
#include <string.h>
#include <iostream>	// cout
#include <cstdlib>	// system
#include <cstring>	// strcpy

using namespace std;

class Bryla
{
    public:
        Bryla(double promien, double wysokosc)
        {
            r = promien;
            h = wysokosc;
        }

         virtual ~Bryla()
        {
            cout << "Bryla usuniety" << endl << endl;
		}

        virtual void wypiszInfo() = 0;

        virtual double obliczObjetosc() = 0;

    protected:
        double r, h;
        static const double PI=3.14;
};

class Walec: public Bryla
{
    public:
        Walec(double promien, double wysokosc): Bryla(promien, wysokosc)
        {
            cout << "Konstruktor z arg. double " << r << ", " << h << " klasy Walec" << endl;
        }
        ~Walec()
        {
            cout << "Destruktor z klasy Walec" << endl;
        }
        virtual void wypiszInfo()
        {
            cout << "Parametry Bryly: Walec" << endl;
            cout << "r = " << r << endl;
            cout << "h = " << h << endl;
        }
        virtual double obliczObjetosc()
        {
            return PI * r * r * h;
        }
};

class Stozek: public Bryla
{
    public:
        Stozek(double promien, double wysokosc): Bryla(promien, wysokosc)
        {
            cout << "Konstruktor z arg. double " << r << ", " << h << " klasy Stozek" << endl;
        }
        ~Stozek()
        {
            cout << "Destruktor z klasy Stozek" << endl;
        }
        virtual void wypiszInfo()
        {
            cout << "Parametry Bryly: Stozek" << endl;
            cout << "r = " << r << endl;
            cout << "h = " << h << endl;
        }
        virtual double obliczObjetosc()
        {
            return (1.0 / 3.0) * PI * r * r * h;
        }
};

class StozekSciety: public Stozek
{
    public:
        StozekSciety(double promienScietejCzesci, double promien, double wysokosc): Stozek(promien, wysokosc)
        {
            cout << "Konstruktor z arg. double " << r << ", " << h << " klasy StozekSciety" << endl;
            R = promienScietejCzesci;
        }
        ~StozekSciety()
        {
            cout << "Destruktor z klasy StozekSciety" << endl;
        }
        virtual void wypiszInfo()
        {
            cout << "Parametry Bryly: Stozek Sciety" << endl;
            cout << "R = " << R << endl;
            cout << "r = " << r << endl;
            cout << "h = " << h << endl;
        }
        virtual double obliczObjetosc()
        {
            return (1.0 / 3.0) * PI * h * (R * R + R * r + r * r);
        }
    protected:
        double R;
};

int main()
{
    cout << "# Tworze obiekty klas: Walec, Stozek, StozekSciety" << endl;
    Bryla *figury_geometryczne[3];
    figury_geometryczne[0] = new Walec(8,5);
    figury_geometryczne[1] = new Stozek(4,3);
    figury_geometryczne[2] = new StozekSciety(1,2,3);
    cout << "--------------------" << endl;
    cout << endl;

    cout << "# Wywoluje metody: wypiszInfo(), oraz obliczObjetosc()" << endl;
    for(int i = 0; i < 3; i++)
    {
        figury_geometryczne[i]->wypiszInfo();
        cout << "V = " << figury_geometryczne[i]->obliczObjetosc() << endl;
        cout << "--------------------" << endl;
    }

    cout << endl;
    cout << "# Usuwam obiekty" << endl;
    for(int i = 0; i < 3; i++)
    {
        delete figury_geometryczne[i];
    }
    cout << endl;

    return 0;
}
