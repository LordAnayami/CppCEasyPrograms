#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float a, b, c, delta, x1, x2, x;

int main()
{
    system("cls"); /*czyszczenie ekranu*/
    printf("%s" , "Podaj zmienn� a: "); /*wyswietlenie*/
	scanf("%f", &a); /*odczytanie z ekranu*/
    printf("%s" , "Podaj zmienn� b: "); /*wyswietlenie*/
	scanf("%f", &b); /*odczytanie z ekranu*/
    printf("%s" , "Podaj zmienn� c: "); /*wyswietlenie*/
	scanf("%f", &c); /*odczytanie z ekranu*/


    delta=b*b - 4.0*a*c;

    if (delta >0)
    {
              x1=(-b+sqrt(delta))/(2.0*a);
              x2=(-b-sqrt(delta))/(2.0*a);
              printf("Wynikiem s� liczby %f i %f", x1,x2);
    }
    if (delta==0)
    {
           x1=-b/(2.0*a);
           printf("Wynikiem jest liczba %f", x1);
    }
    if (delta < 0)
    {
           printf( "Delta mniejsza od 0, brak wynik�w" );
    }
system("pause");
return 0;
}
