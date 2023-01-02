// Hierarchia klas ze zwykla funkcja skladowa graj

#include <iostream>	// cout
#include <cstdlib>	// system
#include <cstring>	// strcpy
using namespace std;

//-----------------------------

class instrument
{
   // wspolne cechy i zachowania wszystkich instrumentow
   public:
      void graj() { cout << "instrument gra" << endl; }
   protected:
      char nazwa[15];
};

//-----------------------------

class dety : public instrument
{
   // wspolne cechy i zachowania instrumentow detych
};

class trabka : public dety
{
   public:
      trabka() { strcpy(nazwa, "trabka"); }
      void graj() { cout << nazwa << " gra TRA-TA-TA" << endl; }
};

//-----------------------------

class perkusyjny : public instrument
{
   // wspolne cechy i zachowania instrumentow perkusyjnych
};

class beben : public perkusyjny
{
   public:
      beben() { strcpy(nazwa, "beben"); }
      void graj() { cout << nazwa << " gra BUM-BUM-BUM" << endl; }
};

//-----------------------------

class klawiszowy : public instrument
{
   // wspolne cechy i zachowania instrumentow klawiszowych
   protected:
	   int liczba_klawiszy;
};

class fortepian : public klawiszowy
{
   public:
      fortepian() { strcpy(nazwa, "fortepian"); liczba_klawiszy = 88; }
      void graj() { cout << nazwa << " gra PLIM-PLIM-PLIM" << endl; }
};

class syntezator : public klawiszowy
{
   public:
      syntezator() { strcpy(nazwa, "syntezator"); liczba_klawiszy = 40; }
      void graj() { cout << nazwa << " gra PI-PI-PI" << endl; }
};

//-----------------------------

int main()
{
   system("cls");

   // tworzenie obiektow
   instrument *orkiestra[5];
   orkiestra[0] = new trabka();
   orkiestra[1] = new beben();
   orkiestra[2] = new fortepian();
   orkiestra[3] = new syntezator();
   orkiestra[4] = new fortepian();

   // wywolanie funkcji graj
   for(int i = 0; i < 5; i++)
      orkiestra[i]->graj(); // wczesne wiazanie (statyczne, na etapie kompilacji)

   // UWAGA: na razie brak usuwania obiektow!

   cout << endl;
   system("pause");
   return 0;
}
