#include <iostream> //cout, sin
#include <cstdlib> //system
using namespace std;

class prostokat //deklaracja klasy
{
public:
    prostokat();
    prostokat(float s, float w);
    /*prostokat(float s, float w) //konstruktor
    {
    wys = s;
    szer = w;
    }*/
    ~prostokat();

    float getWys() {return wys;}
    float getSzer() {return szer;}
    void setWys(float w)
                            {wys = w;}
    void setSzer(float s)
                            {szer = s;}
    float obliczPole();
    float obliczObwod();
private:
    float wys, szer;

};

prostokat::prostokat()  //konst bezargu,emt
{
    wys = 1.0;
    szer = 1.0;
    cout<< "Utworzono obiekt konstr bezargumentowym" <<endl;
}

prostokat::prostokat(float w, float s)  //konst argu,emt
{
    wys = w; szer = s;
    cout<< "Utworzono obiekt konstr z argumentowym" <<endl;
}

prostokat::~prostokat()  //destruktor
{
   cout<< "Zniszczono obiekt destruktorem" <<endl;
}

float prostokat::obliczPole()
{
    return wys*szer;
}

float prostokat::obliczObwod()
{
    return 2*(wys+szer);
}


int main()
{
    system ("cls");
    float w, s;
    prostokat p1;
    prostokat p2(2,3);

    p1.setSzer(2);
    p1.setWys(3);

    cout << "Pole wynosi:" <<p1.obliczPole()<<endl;
    cout << "Obwod wynosi:" <<p1.obliczObwod()<<endl;

    p1.prostokat::~prostokat();

    prostokat *wsk;
    wsk = &p2; //lub new prostokat(4,5);
    cout <<"Pole = " << wsk->obliczPole() <<endl;
    delete wsk; // TU BÊDZIE WYWO£YWANY DESTRUKTOR

    system("pause");
    return 0;
}
