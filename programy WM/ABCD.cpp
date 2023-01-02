// plik ABCD.cpp
// Demonstracja tworzenia i niszczenia obiektów klasy pochodnej.

#include <iostream> // cout
#include <cstdlib>  // system
using namespace std;

class A
{
   public:
      A()      { cout << "Konstruktor bezargumentowy z klasy A" << endl; }
      A(int x) { cout << "Konstruktor z argumentem int " << x << " z klasy A" << endl; }
      ~A()     { cout << "Destruktor z klasy A" << endl; }
};

class B: public A
{
   public:
      B()             { cout << "Konstruktor bezargumentowy z klasy B" << endl; }
      B(int b) : A(b) { cout << "Konstruktor z argumentem int " << b << " z klasy B" << endl; }
               // lista inicjalizuj¹ca: uruchomienie wybranego konstruktora z klasy bazowej A
      B(float x)      { cout << "Konstruktor z argumentem float " << x << " z klasy B" << endl; }
      ~B()            { cout << "Destruktor z klasy B" << endl; }
};

class C: public B
{
   public:
      C() { cout << "Konstruktor bezargumentowy z klasy C" << endl; }
      ~C() { cout << "Destruktor z klasy C" << endl; }
};

class D: private B
{
    public:
      D() { cout << "Konstruktor bezargumentowy z klasy D" << endl; }
      ~D() { cout << "Destruktor z klasy D" << endl; }
};

int main()
{
   system("cls");
   
   {
      A a;    cout << endl;
      B b(5); cout << endl;
      C c;    cout << endl;
   }  // tutaj konczy sie zakres widocznosci obiektow
      // obiekty sa niszczone => destruktory uruchamiane w odwrotnej kolejnosci 
   
   system("pause");
   return 0;
}
