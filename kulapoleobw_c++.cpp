#include <iostream>
#include <math.h>
#include <stdlib.h> /*system*/
using namespace std;



float promien;
float pole, obwod;
const float PI=3.14;

int main()
{
	system("cls"); /*czyszczenie ekranu*/
	cout << "Podaj promien kuli: "; //wyswietlenie
	cin >> promien; //odczytanie z ekranu
	pole=PI*pow(promien, 2);
	obwod=2*PI*promien;
	cout << "Kula o promieniu " << promien << " ma pole"<< pole <<  " i obwod" << obwod;
	system("pause");
	return 0;
}
