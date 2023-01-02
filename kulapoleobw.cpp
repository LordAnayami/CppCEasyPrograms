#include <math.h> /*pi*/
#include <stdio.h> /*f. printf, scanf*/
#include <stdlib.h> /*system*/

float promien;
float pole, obwod;
const float PI=3.14;

int main()
{
	system("cls"); /*czyszczenie ekranu*/
	printf("%s", "Podaj promien kola: "); /*wyswietlenie*/
	scanf("%f", &promien); /*odczytanie z ekranu*/
	pole=PI*pow(promien, 2);
	obwod=2*PI*promien;
	printf("Kula o promieniu %.1f \n ma pole %.2f \n i obwod %.2f \n\n", promien, pole, obwod);
	system("pause");
	return 0;
}
