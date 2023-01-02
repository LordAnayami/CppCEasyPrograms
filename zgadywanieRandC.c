#include <stdlib.h> /*rand, srand, system*/
#include <stdio.h> /*printf, scanf*/
#include <time.h> /*time, pobiera czas z PC*/

int main ()
{
    int i, x, d;

    system("cls");
    srand(time(NULL)); /*bez tego losowanie s¹ ci¹gle te same liczby*/

    printf("%s" , "Podaj liczbê z przedzia³u 1-10: "); /*wyswietlenie*/
	fflush(stdin)/*czysczenie bufora*/; scanf("%i", &i); /*odczytanie z ekranu*/


    x=rand()%10+1; /*przedzial losowania 1..10*/
    printf("Wylosowano %d \n", x);
    do
    {
    if (i>x)
        printf("Podales za duzo");
    else
        if (i<x)
        printf("Poda³es za malo");

    d=d++;
    } while(i !=x);
    printf ("Zgadles liczbe za %d razem \n", d);
    system("pause");
    return 0;
}

