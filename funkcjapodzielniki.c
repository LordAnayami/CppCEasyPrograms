#include <stdio.h> /*printf, scanf*/
#include <math.h> /*system*/
#include <stdlib.h>


int podzielniki(int n)
{

    int i, c;
    system("cls");
    printf("%s" , "Podaj liczbe naturalna n: ");
	fflush(stdin)/*czysczenie bufora*/;
	scanf("%i", &n);



	for (i=1; i<=n/2; i++ )
	{
	if (n % i ==0)
        {
            printf("%d, \n", i);
            c=c+i;
        }
    }


    printf("\n");
    return c;
}
