#include <iostream> //cout, sin
#include <cstdlib> //system
#include <time.h> //time
#include <math.h> //matematyczne funkcje
#include <cmath> //dla pow


using namespace std;

class Tablica //deklaracja tablicy
{
public:
    Tablica();
    int A[];
    Tablica(int rozmiar); //deklaracja tablicy i rozmiaru
    float Losuj();
private:
    int n; //rozmiar tablicy
    int *wsk;

};

float Tablica::Losuj()
{
    int i;
    int rozmiar=10;
    n=rozmiar;
    srand(time(NULL)); /*bez tego losowanie s¹ ci¹gle te same liczby*/
    for ( i=0; i<=rozmiar-1; i++ )
    {
        A[i]=rand()%10+1; /*przedzial losowania 1..10*/
        cout << ("wylosowano %d \n", A[i]) << endl;
    }
}

int main()
{
    system ("clc");
    int n;
    Tablica t1;
    t1.Losuj();


}
