/*Is a type of constructor that creates an object using another object of the same class
  copy initialization or member wise initialization*/


/*Example of shallow copy leads to dangling pointer*/

/*Shallow copy and Deep copy 
In shallow copy object of class copies by member wise but while copy some dynamic memory allocation oor
pointers then its just copy the address of that members

In Deep copy programmers ensure that dynamic memory allocation or pointers are copied by its memory to the 
another location*/

#include<iostream>
using namespace std;

class A 
{
public:
    int *x;

    A(int value)
    {
        x = new int(value);
    }

    ~A()
    {
        delete x;
    }

    void Display() const{
        cout<<"data = "<<*x<<endl;
    }
};

int main()
{
    A a1(1);// = new A(10);
    A obj2 = a1;

    a1.Display();
    a1.A::~A();    
    obj2.Display();


   
    //cout<<"a1 -> x = "<<a1.x<<endl;

    //A a2(a1);
    //cout<<"a2 -> x = "<<a2.x<<endl;


    //A a3 = a2;
    //cout<<"a3 -> x = "<<a3.x<<endl;

    return 0;
}
