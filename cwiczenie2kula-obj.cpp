#include <math.h> /*pi*/
#include <stdio.h> /*f. printf, scanf*/
#include <stdlib.h> /*system*/

float promien;
float objetosc;
const float PI=3.14;

int main()
{
	system("cls"); /*czyszczenie ekranu*/
	printf("%s", "Podaj promien kuli: "); /*wyswietlenie*/
	scanf("%f", &promien); /*odczytanie z ekranu*/
	objetosc=4.0/3.0*PI*pow(promien, 3); 
	printf("Kula o promieniu %.1f ma objetosc %.1f \n\n", promien, objetosc);
	system("pause");
	return 0;
}
