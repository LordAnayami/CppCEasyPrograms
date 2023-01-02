#include <stdio.h> /*printf, scanf*/
#include <math.h> /*system*/
#include <stdlib.h>

int n, i, c;


int main()
{
    int suma =0; /*zmienna lokalna*/
    system("cls");
    printf("%s" , "Podaj liczbe naturalna n: ");
	fflush(stdin)/*czysczenie bufora*/; scanf("%i", &n);



	for (i=1; i<=n/2; i++ )
	{
	if (n % i ==0)
        {
            printf("%d, \n", i);
            c=c+i;
        }
    }



    printf("Suma podzielnikow rowna sie %10i \n", c);
    if (n==c)
        printf("Liczba %d jest liczba doskonala \n",n);
    else
        printf("Liczba %d nie jest liczba doskonala \n",n);
    system("pause");
    return 0;
}
