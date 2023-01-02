#include <stdlib.h> /*rand, srand, system*/
#include <stdio.h> /*printf, scanf*/
#include <time.h> /*time, pobiera czas z PC*/

int main ()
{
    int n, i;
    int *tab;
    FILE *plik;

    printf("Podaj ilosc liczb losowych \n");
    scanf("%d", &n);


    tab=(int*) malloc(n*sizeof(int));
    /*calloc(N, sizeof(int))*/

    if (tab==NULL)
    {
        printf("Brak pamiêci");
        exit(-1);
    }

    srand(time(NULL));

    for (i=0; i<n; i++)
   {
        tab[i]=rand()%11;
        printf("Tablica %d \n", tab[i]);
   }

   plik = fopen("liczby.txt", "wt");
   if (plik==NULL)
   {
       printf("Problem z otwarciem pliku\n");
        exit(-2);
   }
   for (i =0; i<n; i++)
        fprintf(plik, "%d ", tab[i]);

    fclose(plik);
   free(n);
   return 0;
}
