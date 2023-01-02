#include <stdlib.h> /*rand, srand, system*/
#include <stdio.h> /*printf, scanf*/
#include <time.h> /*time, pobiera czas z PC*/

int main ()
{
    int i, liczba;

    system("cls");
    srand(time(NULL)); /*bez tego losowanie s¹ ci¹gle te same liczby*/
    for ( i=1; i<=5; i++ )
    {
        liczba=rand()%10+1; /*przedzial losowania 1..10*/
        printf("wylosowano %d \n", liczba);
    }

    system("pause");
    return 0;
}
