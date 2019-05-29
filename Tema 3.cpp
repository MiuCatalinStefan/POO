#include <iostream>
#include<string.h>

using namespace std;

class coupe;
class coupe_4usi;
class hot_hatch;
class super_sport;
class masina;

template<typename T>

class Expozitie
{
    T *obiecte;
    int nr_obiecte;
public:
   Expozitie();
 virtual ~Expozitie();
 friend class masina;
   void Afisare();
};

template<class T>Expozitie<T>::Expozitie()
{
    int a;
    cout<<"Introdu numarul total de masini din expozitie: ";
    cin>>a;
    nr_obiecte=a;
    obiecte= new<T>static_cast<masina>(*a);
}

template<class T>Expozitie<T>::~Expozitie()
{
    delete obiecte;
}

template<class T>void Expozitie<T>::Afisare()
{
    for(int i=0;i<this->nr_obiecte;i++)
    {
        this->obiecte[i].afisare_test();
    }
}

class masina
{
    char producator[20];
    char nume_model[30];
    char culoare[10];
    float capacitate_motor;
    char combustibil[20];

public:
    masina();
   void afisare_test();

};

masina::masina()
{
    cout<<"Introdu numele producatorului: ";
    cin>>this->producator;
    cout<<endl<<"Introdu numele modelului: ";
    cin>>this->nume_model;
    cout<<endl<<"Introdu culoarea automobilului: ";
    cin>>this->culoare;
    cout<<endl<<"Introdu capacitatea motorului in litrii: ";
    cin>>this->capacitate_motor;
    cout<<endl<<"Introdu tipul de combustibil folosit de autovehicul: ";
    cin>>this->combustibil;
    cout<<endl<<endl<<endl;
}

void masina::afisare_test()
{
    cout<<this->producator<<" ";
    cout<<this->nume_model<<" :"<<endl;
    cout<<"Culuoare: "<<this->culoare<<", ";
    cout<<"Capacitate motor in litrii:"<<this->capacitate_motor<<", ";
    cout<<"Combustibil: "<<this->combustibil<<endl;
}

class coupe: public masina
{
public:

};

class coupe_4usi: public masina
{
public:

};

class hot_hatch: public masina
{
public:

};

class super_sport: public masina
{
    int pret;
    float kilometraj;
    bool vandut=0;
public:
    super_sport();
    void operator=(const int a);
};

super_sport::super_sport():masina()
{
    cout<<"Introdu pretul: ";
    cin>>pret;
    cout<<"Introdu kilometraj: ";
    cin>>kilometraj;
}

void super_sport::operator=(const int a)
{

}


int main()
{
  Expozitie <masina> Auto_Expo;
  Auto_Expo.Afisare();
  return 0;
}
