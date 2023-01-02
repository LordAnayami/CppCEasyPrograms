#include <iostream>
#include <cstdlib>
using namespace std;

class prostokat //deklaracja klasy
{
public:
    prostokat() //konstruktor
    {
        wysokosc = 1.0;
        szerokosc = 1.0;
    }
    float obliczPole();
    float obliczObwod();

    //funkcje udostêpniaj¹ce:
    float getWysokosc() (return wysokosc;)
    float getSzerokosc() (return szerokosc;
    void setWysokosc(float X) (wysokosc = X;)
    void setSzerokosc(float Y) (szerokosc = Y;)
}

prostokat::prostokat(float X, Y)
{
    wysokosc = X;
    szerokosc = Y;

}

float prostokat::obliczPole()
{
    return wysokosc*szerokosc;
}

float prostokat::obliczObwod()
{
    return 2*(wysokosc+szerokosc);
}

int main()
{
    system ("cls");

    cout << "Podaj wysokosc prostokata" <<endl;
    cin >> X;
    cout << "Podaj szerokosc prostokata" <<endl;
    cin >> Y;

    cout << "Pole wynosi:" <<kl.obliczPole()<<endl;
    cout << "Obwod wynosi:" <<kl.obliczObwod()<<endl;

    system("pause");
    return 0;
}
