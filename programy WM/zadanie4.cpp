#include <iostream>

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
            std::cout << "Destruktor z klasy Bryla" << std::endl;
            std::cout << "--------------------" << std::endl;
        }
        virtual void wypiszInfo() = 0;
        virtual double obliczObjetosc() = 0;
    protected:
        double r, h;
        static const double PI;
};
const double Bryla::PI = 3.14159;

class Walec: public Bryla
{
    public:
        Walec(double promien, double wysokosc): Bryla(promien, wysokosc)
        {
            std::cout << "Konstruktor z arg. double " << r << ", " << h << " klasy Walec" << std::endl;
        }
        ~Walec()
        {
            std::cout << "Destruktor z klasy Walec" << std::endl;
        }
        virtual void wypiszInfo()
        {
            std::cout << "Parametry Bryly: Walec" << std::endl;
            std::cout << "r = " << r << std::endl;
            std::cout << "h = " << h << std::endl;
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
            std::cout << "Konstruktor z arg. double " << r << ", " << h << " klasy Stozek" << std::endl;
        }
        ~Stozek()
        {
            std::cout << "Destruktor z klasy Stozek" << std::endl;
        }
        virtual void wypiszInfo()
        {
            std::cout << "Parametry Bryly: Stozek" << std::endl;
            std::cout << "r = " << r << std::endl;
            std::cout << "h = " << h << std::endl;
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
            std::cout << "Konstruktor z arg. double " << r << ", " << h << " klasy StozekSciety" << std::endl;
            R = promienScietejCzesci;
        }
        ~StozekSciety()
        {
            std::cout << "Destruktor z klasy StozekSciety" << std::endl;
        }
        virtual void wypiszInfo()
        {
            std::cout << "Parametry Bryly: Stozek Sciety" << std::endl;
            std::cout << "R = " << R << std::endl;
            std::cout << "r = " << r << std::endl;
            std::cout << "h = " << h << std::endl;
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
    std::cout << "# Tworze obiekty klas: Walec, Stozek, StozekSciety" << std::endl;
    Bryla *figury_geometryczne[3];
    figury_geometryczne[0] = new Walec(8,5);
    figury_geometryczne[1] = new Stozek(4,3);
    figury_geometryczne[2] = new StozekSciety(1,2,3);
    std::cout << "--------------------" << std::endl;
    std::cout << std::endl;

    std::cout << "# Wywoluje metody: wypiszInfo(), oraz obliczObjetosc()" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        figury_geometryczne[i]->wypiszInfo();
        std::cout << "V = " << figury_geometryczne[i]->obliczObjetosc() << std::endl;
        std::cout << "--------------------" << std::endl;
    }

    std::cout << std::endl;
    std::cout << "# Usuwam obiekty" << std::endl;
    for(int i = 0; i < 3; i++)
    {
        delete figury_geometryczne[i];
    }
    std::cout << std::endl;

    return 0;
}
