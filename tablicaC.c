#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int A[5];
int suma, i, sumap, sumanp, min, max,c ;
float sraryt;

int main()
{
system("cls");
srand(time(NULL));


/*tworzenie liczb*/
printf("Tablica A sklada sie z:\n");
for (i=0; i<5; i++)
   {
    A[i]=rand()%10+1;
    c=i+1;
    printf("A(%d) = %d \n",c, A[i]);
   }



/*suma i œrednia arytmetyczna*/
for (i=0; i<5; i++)
   {
    suma=suma+A[i];
    }
sraryt=suma/5.0;



/*suma parzysta i nieparzysta*/

for (i=0; i<5; i++)
   {
    sumap=(A[i]%2==0 ? sumap=sumap+A[i] : sumap);
    sumanp=(A[i]%2==1 ? sumanp=sumanp+A[i] : sumanp);

   }


/*min  i max*/
min=A[0];
max=A[0];
for (i=1; i<5; i++)
   {
    A[i-1];
    A[i];
   min=(min<A[i]? min:A[i]);
   max=(max>A[i]? max:A[i]);
   }

/*wyniki*/

    printf("\nWyniki:\n");
    printf("a) Suma rowna sie %d \n",suma);
    printf("b) Suma parzysta rowna sie %d \n",sumap);
    printf("c) Suma nieparzysta rowna sie %d \n",sumanp);
    printf("d) Srednia arytmetyczna %f \n",sraryt);
    printf("e) Min %d \n",min);
    printf("f) Max %d \n",max);
    system("pause");
    return 0;
}
