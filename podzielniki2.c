#include <stdio.h> /*printf, scanf*/
#include <math.h> /*system*/
#include <stdlib.h>

int main()
{

    int x=6;
    system("cls");
    printf("%s" , "Podaj liczbe naturalna n: ");
	fflush(stdin)/*czysczenie bufora*/;
	scanf("%i", &x);
    printf("Suma podzielnikow liczby %d wynosi %d\n", x, podzielniki(x));
    /*
    int wynik;
    wynik = podzielniki(x);
    printf("%d", wynik);
    */

    if (czyDoskonala(x) == 1)
        printf("Liczba %d jest doskonala\n", x);

    return 0;
}


int podzielniki(int n)
{

    int i, suma =0;


	for (i=1; i<=n/2; i++ )
        if (n % i ==0)
        {
            printf("%d, \n", i);
            suma+=i;
        }


    return suma;
}


int czyDoskonala(int n)
{
   if (n == podzielniki(n))
        return 1;
    else
        return 0;

}
