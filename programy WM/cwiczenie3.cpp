#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>

using namespace std;

class mac {
    private:
		int n;
		int *wsk;
		float re;
        float im;

	public:

		mac()
		{
			n=3;
			wsk=new int[n];
			for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
				wsk[i,j]=0;
		}

		mac(int liczba, int liczba2)
		{
			n=liczba;
			wsk=new int[liczba];
			for(int i=0;i<liczba;i++)
				 for(int j=0;j<n;j++)
				wsk[i,j]=0;
		}

        int get(int i, int j)
		{
			return wsk[i,j];
		}

		void set(int i, int j,int c)
		{
			wsk[i,j]=c;
		}
		mac(const mac &t)
		{
			n = t.n;
           wsk = new int[n];
           for (int i = 0; i < n; i++)
             for (int j = 0; j < n; j++)
           wsk[i,j] = t.wsk[i,j];
		}

		~mac(){
		}

        int get(long i,long j)
		{
			return wsk[i,j];
		}

		void set(int i,int j)
		{
			wsk[i,j]=3;
		}

		void losuj()
		{
			for(int i=0;i<n;i++)
			{
			    for(int j=0;j<n;j++)
			{
			wsk[i,j] = 1 + rand() % 10;
			}
			}
		}

		void wypisz()
		{
			for(int i=0;i<n;i++)
            {for(int j=0;j<n;j++)
			cout << wsk[i,j] << " ";}
			cout <<endl;
		}

        mac operator+(mac t);


};


mac mac::operator +(mac t)
{
   mac wynik;
   for(int i=0;i<n;i++)
            {for(int j=0;j<n;j++)
   {wynik.wsk[i],[j]=wsk[i],[j]+t.wsk[i],[j];}
   return wynik;
			}
}



int main(){
	srand(time(NULL));

	mac tab10;
	mac *m1=new mac[3,3];
	mac *m2=new mac[3,3];
    mac *m3=new mac[3,3];


	m1->set(1,3);
	m2->set(1,3);
	cout << "6 element Tablicy 1: " << m1->get(2,3) << endl;
	cout << "6 element Tablicy 2(kontruktor kopiujacy): " << m2->get(2,3) << endl <<endl;

	m1->losuj();
	cout << "Tablica 1:" << endl;
	m1->wypisz();
	cout << endl << endl;

	m2->losuj();
	cout << "Tablica 2(konstruktor kopiujacy):" << endl;
	m2->wypisz();
	cout << endl << endl;


    m3 = m1 + m2;
    m3->wypisz();
	cout << endl << endl;


	delete m1;
	delete m2;
	delete m3;
	return 0;
}
