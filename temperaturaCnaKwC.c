#include <stdio.h> /*printf, scanf*/
#include <math.h> /*system*/
#include <stdlib.h>

int a, b, k, i, t;


int main()
{
    system("cls"); /*czyszczenie ekranu*/
    printf("%s" , "Podaj poczatek zakresu temperatur a: "); /*wyswietlenie*/
	fflush(stdin)/*czysczenie bufora*/; scanf("%i", &a); /*odczytanie z ekranu*/
    printf("%s" , "Podaj koniec zakresu temperatur b: "); /*wyswietlenie*/
	fflush(stdin)/*czysczenie bufora*/; scanf("%i", &b); /*odczytanie z ekranu*/
    printf("%s" , "Podaj przyrost temperatur k: "); /*wyswietlenie*/
	fflush(stdin)/*czysczenie bufora*/; scanf("%i", &k); /*odczytanie z ekranu*/
    printf ("%10s %10s \n", "temp C, tempF");
	for (i=a; i<=b; i=i+k )
	{
    t=9.0/5*i+32;
    printf("%10i C %10iF\n", i, t); /*wyswietlenie*/
    }

}
