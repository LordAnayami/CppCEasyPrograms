#include <iostream> //cout, sin
#include <cstdlib> //system
#include <time.h> //time
#include <math.h> //matematyczne funkcje

using namespace std;

class Tablica { //deklaracja tablicy
    private:
		int n;
		int *wsk;


	public:

		Tablica() //deklaracja tablicy
		{
			n=10;
			wsk=new int[n];
			for(int i=0;i<10;i++)
				wsk[i]=0;
		}

		Tablica(int liczba)
		{
			n=liczba;
			wsk=new int[liczba];
			for(int i=0;i<liczba;i++)
				wsk[i]=0;
		}

		Tablica(const Tablica &t)
		{
			n = t.n;
           wsk = new int[n];
           for (int i = 0; i < n; i++)
           wsk[i] = t.wsk[i];
		}

		~Tablica(){ //destruktor
		}

		int get(int i)
		{
			return wsk[i];
		}

		void set(int i, int j)
		{
			wsk[i]=j;
		}

		void losuj()
		{
			for(int i=0;i<n;i++)
			{
			wsk[i] = 1 + rand() % 10;
			}
		}

		void wypisz()
		{
			for(int i=0;i<n;i++)
			cout << wsk[i] << " ";
		}

		float avg()
		{
			int sum=0;
			for(int i=0;i<n;i++)
				sum=wsk[i]+sum;

			return sum/n;
		}

		float geom()
		{
			int ilo=1;
			for(int i=0;i<n;i++)
				ilo=ilo*wsk[i];

			return pow(ilo,1/n);
		}

		int minimum()
		{
			int temp=wsk[0];
			for(int i=0;i<n;i++)
				if(wsk[i]<temp)
					temp=wsk[i];

			return temp;
		}

		int maksimum()
		{
			int temp=wsk[0];
			for(int i=0;i<n;i++)
				if(wsk[i]>temp)
					temp=wsk[i];

			return temp;
		}

		void sortuj()
		{
			int temp;
			for(int i=0;i<=n;i++)
				for(int j=1;j<n;j++)
					if(wsk[j]<wsk[j-1])
					{
						temp=wsk[j];
						wsk[j]=wsk[j-1];
						wsk[j-1]=temp;
					}
		}

		float mediana()
		{
			if(n%2==1)
				return wsk[n/2];
			else
				return (wsk[(n-1)/2]+wsk[n/2])/2.0;
		}
};

int main(){
	srand(time(NULL));

	Tablica tab10;
	Tablica *tab=new Tablica(15);
	Tablica *tab2=new Tablica(*tab);

	if(tab->get(0) == 0 && tab2->get(0)==0) // sprawdzenie czy zerowa wartoœæ wskaznika wskazuje na pierwszy element wyzerowanej tablicy
		cout << "Przydzial pamieci poprawny!" << endl << endl;

	tab->set(5,3);
	tab2->set(5,8);
	cout << "6 element Tablicy 1: " << tab->get(5) << endl;
	cout << "6 element Tablicy 2(kontruktor kopiujacy): " << tab2->get(5) << endl <<endl;

	tab->losuj();
	cout << "Tablica 1:" << endl;
	tab->wypisz();
	cout << endl << endl;

	tab2->losuj();
	cout << "Tablica 2(konstruktor kopiujacy):" << endl;
	tab2->wypisz();
	cout << endl << endl;

	tab->sortuj();
	cout<< "Posortowana Tablica 1:";
	tab->wypisz();
	cout << endl << endl;

	tab2->sortuj();
	cout << "Posortowana Tablica 2:" ;
	tab2->wypisz();
	cout << endl << endl;

	cout << "Minimum Tablicy 1: " << tab->minimum();
	cout << endl;
	cout << "Maximum Tablicy 1: " << tab->maksimum();
	cout << endl << endl;

	cout << "Minimum Tablicy 2: " << tab2->minimum();
	cout << endl;
	cout << "Maximum Tablicy 2: " << tab2->maksimum();
	cout << endl << endl;

	cout << "Mediana Tablica 1: ";
	cout << tab->mediana();
	cout << endl;
	cout << "Mediana Tablica 2: ";
	cout << tab2->mediana();
	cout << endl << endl;

	cout << "Srednia Tablicy 1: " << tab->avg();
	cout << endl << endl;
	cout << "Srednia Tablicy 2: " << tab2->avg();
	cout << endl << endl;

	cout << "Srednia geometryczna dla Talbicy 1: " << tab->geom();
	cout << endl << endl;
	cout << "Srednia geometryczna dla Talbicy 2: " << tab2->geom();
	cout << endl << endl;

	delete tab;
	delete tab2;
	return 0;
}
