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
        cout << "Konstruktor z argumentem double " << r << ", " << h << " dla klasy Walec" << endl<< endl;
    }

    ~Walec(){ cout << "Walec usuniety" << endl;
		}
    virtual void wypiszInfo()
    {
        cout << "Wartosc promienia podstawy walca wynosi " << r << endl;
        cout << "Wartosc wysokosci walca wynosi " << h << endl;
    }

    virtual double obliczObjetosc()
    {
    return 2*PI*r*r*h;
    }
};


class Stozek: public Bryla
{
public:
    Stozek(double promien, double wysokosc): Bryla(promien, wysokosc)
{
            cout << "Konstruktor z argumentem double " << r << ", " << h << " dla klasy Stozek" << endl<< endl;
}

    ~Stozek()
        {
        cout << "Stozek usuniety" << endl;
		}


	virtual void wypiszInfo()
    {
        cout << "Wartosc promienia podstawy stozka wynosi " << r << endl;
        cout << "Wartosc wysokosci stozka wynosi " << h << endl;
    }

    virtual double obliczObjetosc()
    {
        return PI*r*r*h/3;
    }
};

class StozekSciety: public Stozek
{
  public:

      StozekSciety(double promienSciety, double promien, double wysokosc): Stozek(promien, wysokosc)
        {
             R = promienSciety;
             cout << "Konstruktor z argumentem double " << r << ", " << R << ", " << h  << " dla klasy StozekSciety" << endl;

        }

    virtual void wypiszInfo()
    {
        cout << "Wartosc promienia dolnej podstawy stozka scietego wynosi " << r << endl;
        cout << "Wartosc promienia gornej podstawy stozka scietego wynosi " << R << endl;
        cout << "Wartosc wysokosci stozka scietego wynosi " << h << endl;
    }

    ~StozekSciety(){cout << "StozekSciety usuniety" << endl;
		}

    virtual double obliczObjetosc()
    {
    double Obj=PI*(r*r+r*R+R*R)*h/3;
    return Obj;
    }
    protected:
        double R;
};


int main()
{

system("cls");

// tworzenie obiektow
cout << "Tworze obiekty klas: Walec, Stozek, StozekSciety" << endl;
Bryla *Bryla[3];
Bryla[0] = new Walec(4,5);
Bryla[1] = new Stozek(8,7);
Bryla[2] = new StozekSciety(2,6,3);


//Wypis wartosci obiektow
cout << endl<<  "Wartosci dla: Walec, Stozek, StozekSciety wynosza" << endl;
for(int i = 0; i < 3; i++)
{Bryla[i]->wypiszInfo(); // pozne wiazanie (dynamiczne, podczas dzialania programu)
cout << "Objetosc wynosi " << Bryla[i]->obliczObjetosc()<< endl<< endl;
}


cout << endl;
// usuwanie obiektow - wirtualny destruktor
for(int i = 0; i < 3; i++)
{delete Bryla[i]; }// tutaj uruchamiane sa wirtualne destruktory


system("pause");
return 0;
}

