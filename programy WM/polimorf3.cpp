// Hierarchia klas z destruktorami ktore nie sa wirtualne

#include <iostream>	// cout
#include <cstdlib>	// system
#include <cstring>	// strcpy
using namespace std;

//-----------------------------

// klasa abstrakcyjna
class instrument
{
   public:
      ~instrument() { cout << "destruktor instrumentu" << endl; }
      virtual void graj() = 0; // funkcja czysto wirtualna
   protected:
      char nazwa[15];
};

//-----------------------------

// klasa abstrakcyjna
class dety : public instrument
{
   public:
      ~dety() { cout << "destruktor detego" << endl; }
      virtual void graj() = 0; // funkcja czysto wirtualna
};

class trabka : public dety
{
   public:
      trabka() { strcpy(nazwa, "trabka"); }
      ~trabka() { cout << "destruktor trabki" << endl; }
      virtual void graj() { cout << nazwa << " gra TRA-TA-TA" << endl; }
};

//-----------------------------

// klasa abstrakcyjna
class perkusyjny : public instrument
{
   public:
      ~perkusyjny() { cout << "destruktor perkusyjnego" << endl; }
      virtual void graj() = 0; // funkcja czysto wirtualna
};

class beben : public perkusyjny
{
   public:
      beben() { strcpy(nazwa, "beben"); }
      ~beben() { cout << "destruktor bebna" << endl; }
      virtual void graj() { cout << nazwa << " gra BUM-BUM-BUM" << endl; }
};

//-----------------------------

// klasa abstrakcyjna
class klawiszowy : public instrument
{
   public:
      ~klawiszowy() { cout << "destruktor klawiszowego" << endl; }
      virtual void graj() = 0; // funkcja czysto wirtualna
   protected:
	   int liczba_klawiszy;
};

class fortepian : public klawiszowy
{
   public:
      fortepian() { strcpy(nazwa, "fortepian"); liczba_klawiszy = 50; }
      ~fortepian() { cout << "destruktor fortepianu" << endl; }
      virtual void graj() { cout << nazwa << " gra PLIM-PLIM-PLIM" << endl; }
};

class syntezator : public klawiszowy
{
   public:
      syntezator() { strcpy(nazwa, "syntezator"); liczba_klawiszy = 40; }
      ~syntezator() { cout << "destruktor syntezatora" << endl; }
      virtual void graj() { cout << nazwa << " gra PI-PI-PI" << endl; }
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

   // wywolanie funkcji wirtualnej
   for(int i = 0; i < 5; i++)
      orkiestra[i]->graj();

   cout << endl;
   // niepoprawne usuwanie obiektow - destruktor nie jest wirtualny
   for(int i = 0; i < 5; i++)
      delete orkiestra[i]; // tutaj uruchamiany jest destruktor

   cout << endl;
   system("pause");
   return 0;
}
