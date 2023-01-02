#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float a, b, c, d, e, f, W, Wx, Wy, x, y;

int main()
{
    system("cls"); /*czyszczenie ekranu*/
    printf("%s" , "Podaj zmienna a, b, c, d, e oraz f \n"); /*wyswietlenie*/
	scanf("%f%f%f%f%f%f", &a,&b,&c,&d,&e,&f); /*odczytanie z ekranu*/


    W=a*e-b*d;
    Wx=c*e-b*f;
    Wy=a*f-c*d;
    printf("%f , %f, %f \n", W, Wx, Wy);

    if (W != 0)
    {
        x=Wx/W;
        y=Wy/W;

        printf("Wynikami s¹ liczby: x= %f i y= %f \n", x,y );

    }
    else
        {
        if (W == 0 && Wx == 0 && Wy == 0)
                {
                   printf("Nieskonczenie wiele rozwiazan.\n" ) ;
                }
        if (W == 0 && (Wx != 0 || Wy != 0))
                {
                printf("Uk³ad jest sprzeczny.\n" );
                }
        }
system("pause");
return 0;

}
