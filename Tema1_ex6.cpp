#include <iostream>
using namespace std;

/** Clasa Nod al unei liste*/
class Nod
{
    int info;
    Nod *next;
    Nod *prev;
    public:
    Nod(int info,Nod* next=0);
    int getInfo();
    void setInfo(int info);
    Nod* getNext();
    Nod* getPrev();
    void setNext(Nod* next);
    friend class Lista;
};

Nod::Nod(int info, Nod* next)
{
    this->info=info;
    this->next=next;
}

int Nod::getInfo()
{
    return info;
}

void Nod::setInfo(int info)
{
    this->info=info;
}

Nod* Nod::getNext()
{
    return next;
}

Nod* Nod::getPrev()
{
    return prev;
}

void Nod::setNext(Nod* next)
{
    this->next=next;
}

/** Clasa Lista simplu inlatuita*/
class Lista
{
    protected:
    Nod *prim;
    Nod *ultim;
    public:
    Lista();
    ~Lista();
    int isEmpty();
    void addElement(Nod n);
    void deleteElement();
    Nod* getFirst();
    Nod* getLast();
    Nod* getElementAt( int index);
    friend ostream& operator<<(ostream& out, Lista&);
    friend istream& operator>>(ostream& in, Lista&);
    Lista operator+ (Lista& A);
};

  Lista::Lista()
{
prim=ultim=0;
}

Lista::~Lista()
{
    Nod *p=prim;
    Nod *q;
    while(p!=0)
    {
    q = p;
    p = p->next;
    delete q;
    }
    prim=ultim = 0;
}

int Lista::isEmpty()
{
    return prim==0;
}

void Lista::addElement(Nod n)
{
    Nod *p;
    p=new Nod(n.info,0);
    if(isEmpty())
    {
    prim=ultim=p;
    }
        else
        {
        ultim->next=p;
        p->prev=ultim;
        ultim = p;
        prim->prev=NULL;
        }
}

 Nod* Lista::getFirst()
{
    return prim;
}

Nod* Lista::getLast()
{
    return ultim;
}

Nod* Lista::getElementAt(int index)
{
    Nod* p;
    int i;
    for(i=0,p=prim;i<index&&p!=0;i++,p=p->next);
    return p;
}

void Lista::deleteElement()
{
    Nod *p=ultim->prev;
    ultim->prev=ultim->next;
    delete ultim;
    ultim=p;
    ultim->next=NULL;

}

ostream& operator<<(ostream& out, Lista& lista)
{
    Nod * p=lista.getFirst();
    out<<"Continutul Listei de la cap la coada:";
    while(p)
    {
        out<<p->getInfo()<<",";
        p=p->getNext();
    }
    out<<"\b ";
    out<<endl;
    p=lista.getLast();
    out<<"Continutul Listei de la coada la cap:";
    while(p)
    {
        out<<p->getInfo()<<",";
        p=p->getPrev();
    }
    out<<"\b ";
    return out;
}

istream& operator>>(istream& in, Lista& lista)
{
    int n;
    in>>n;
    lista.addElement(Nod(n));
    return in;
}


Lista Lista::operator+(Lista& A)
{
    int n;
    Lista C;
    Nod* p=this->getFirst();
    while(p)
    {
        n=p->getInfo();
        C.addElement(Nod(n));
        p=p->getNext();
    }
    //cout<<C;
    return C;
}

int main()
{
    Lista B;
    Lista A;
    cout<<"Prima lista: ";
    cin>>A>>A;
    cout<<endl<<"A-doua Lista:";
    cin>>B>>B;
    Lista C=(B+A);
    cout<<C<<endl;
    return 0;
}
