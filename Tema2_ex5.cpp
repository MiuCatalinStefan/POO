#include <iostream>

using namespace std;
/** Clasa numerelor perche**/
class Multime_pereche;
class Coada_Pereche;
class Stiva_Pereche;

class Pereche
{
private:
    int prim;
    int doi;
public:
    Pereche();
    friend class Multime_pereche;
    friend class Coada_Pereche;
    friend class Stiva_Pereche;
    friend class Stiva_Pereche;
};

Pereche::Pereche()
{

}

/** Clasa care formeaza multimi de tip pereche**/
class Multime_pereche
{
protected:
    int n;
    Pereche *p;
    int poz;
public:
    Multime_pereche();
    Multime_pereche(int a);
    void Afisare();
};

Multime_pereche::Multime_pereche(int a)
{
   n=a;
   poz=0;
   p=new Pereche[n];
}

void Multime_pereche::Afisare()
{
    cout<<"Perechile sunt: "<<endl;
    for(int i=0;i<poz;i++)
    {
        cout<<p[i].prim<<","<<p[i].doi<<endl;
    }
}

/** Clasa care mosteneste multimi si functioneaza ca o lista**/
class Coada_Pereche: public Multime_pereche
{
public:
   Coada_Pereche(int a);
  ~Coada_Pereche();
   void Adaugare();
   void Stergere_ultim_element();
   void Stergere_element();

};

Coada_Pereche::Coada_Pereche(int a):Multime_pereche(a)
{

}

Coada_Pereche::~Coada_Pereche()
{
    delete(p);
}

void Coada_Pereche::Adaugare()
{
    if(poz==n)
       {
           cout<<"Vectorul este plin dar se face loc..."<<endl;
           Pereche *g=new Pereche[n];
           for(int i=0;i<n;i++)
           {
               g[i]=p[i];
           }
           delete (p);
           n=n*2;
           p=new Pereche [n];
           for(int i=0;i<poz;i++)
            p[i]=g[i];
           cout<<endl;
           cout<<"Introdu o pereche: ";
           cin>>this->p[poz].prim;
           cout<<",";
           cin>>this->p[poz].doi;
           poz++;
           cout<<"Am facut loc de inca: "<<n/2<<" elemente"<<endl;
           delete (g);
       }
    else
    {
        cout<<"Introdu o pereche: ";
        cin>>this->p[poz].prim;
        cout<<",";
        cin>>this->p[poz].doi;
        poz++;
    }
}

void Coada_Pereche::Stergere_ultim_element()
{
    cout<<"AM STERS ULTIMUL ELEMENT!!!"<<endl;
    poz--;
}

void Coada_Pereche::Stergere_element()
{
    cout<<"Introdu pozitia de pe care vrei sa stergi numarul: ";
    int k;
    cin>>k;
    for(int i=0;i<poz;i++)
    {
        if(i>=k)
        {
            p[i]=p[i+1];
        }
    }
    poz--;
}

/** Clasa care mosteneste multimi si functioneaza ca o stiva folosind 2 cozi si scotandu-mi peri albi fiindca e cel mai useless lucru facut pana acum de mine jeeeeeeeezzzz**/
class Stiva_Pereche: public Multime_pereche
{
private:
    Pereche *d;
public:
    Stiva_Pereche(int a);
   ~Stiva_Pereche();
    void Adaugare_element();
    void Afisare_cap();
    void Stergere_cap();
    void Sterger_element();
};

Stiva_Pereche::Stiva_Pereche(int a):Multime_pereche(a)
{
    d=new Pereche[a];
}

Stiva_Pereche::~Stiva_Pereche()
{
    delete(p);
    delete(d);
}

void Stiva_Pereche::Adaugare_element()
{
     if(poz==n)
       {
           cout<<"Vectorul este plin dar se face loc..."<<endl;
           for(int i=0;i<n;i++)
           {
               d[i]=p[i];
           }
           delete (p);
           n=n*2;
           p=new Pereche [n];
        cout<<"Introdu o pereche: ";
        cin>>this->p[0].prim;
        cout<<",";
        cin>>this->p[0].doi;
          for(int i=1;i<=poz;i++)
            {
                p[i]=d[i-1];
            }
         poz++;
          cout<<"Am facut loc de inca: "<<n/2<<" elemente"<<endl;
       }
    else
    {
        if(poz==0)
        {
            cout<<"Introdu o pereche: ";
            cin>>this->p[poz].prim;
            cout<<",";
            cin>>this->p[poz].doi;
            poz++;
        }
        else
        {
            for(int i=0;i<poz;i++)
            {
                d[i]=p[i];
            }

            cout<<"Introdu o pereche: ";
            cin>>this->p[0].prim;
            cout<<",";
            cin>>this->p[0].doi;

            for(int i=1;i<=poz;i++)
            {
                p[i]=d[i-1];
            }
            poz++;
        }
    }
    delete (d);
    d=new Pereche[n];
}

void Stiva_Pereche::Afisare_cap()
{
    for(int i=0; i<poz;i++)
    {
        if(i==poz)
            cout<<"Capul este: "<<p[i].prim<<","<<p[i].doi;
    }
}


void Stiva_Pereche::Stergere_cap()
{
    cout<<"AM STERS CAPUL STIVEI!!!"<<endl;
    poz--;
}


void Stiva_Pereche::Sterger_element()
{
     cout<<"Introdu pozitia de pe care vrei sa stergi numarul: ";
    int k;
    cin>>k;
    for(int i=0;i<poz;i++)
    {
        if(k!=i)
        {
            d[i]=p[i];
        }
        for(int i=0;i<poz;i++)
        {
            p[i]=d[i];
        }
    }
    poz--;
}

int main()
{
    Stiva_Pereche b(5);
    b.Adaugare_element();
    b.Adaugare_element();
    b.Adaugare_element();
    b.Afisare();
    b.Sterger_element();
    b.Adaugare_element();
    b.Stergere_cap();
    b.Adaugare_element();
    b.Adaugare_element();
    b.Afisare();
    return 0;
}
