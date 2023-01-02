#include <iostream>
#include <math.h>
using namespace std;


float promien;
float objetosc;
const float PI=3.14;

int main()
{
	cout << "Podaj promien kuli: "; //wyswietlenie
	cin >> promien; //odczytanie z ekranu
	objetosc=4.0/3.0*PI*pow(promien, 3); 
	cout << "Kula o promieniu" <<promien << " ma objetosc " << objetosc << endl;

	return 0;
}
