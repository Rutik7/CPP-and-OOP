/*Operator overloading is a compile-time polymorphism. 
It is an idea of giving special meaning to an existing operator in C++ 
without changing its original meaning.*/

#include <iostream>
using namespace std;

class Vector 
{
private:
    float x, y; 

public:
    // Constructor
    Vector(float x = 0, float y = 0) : x(x), y(y) {}

    // Overload the + operator
    Vector operator+(const Vector& other) {
        return Vector(x + other.x, y + other.y);
    }

    // Function to display the vector
    void display() const {
        cout << "Vector(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Vector v1(2.3,3.4);
    v1.display();

    Vector v2(10.2,4);
    v2.display();

    Vector v3 = v1 + v2;

    Vector v4 = v1.operator+(v2);

    v3.display();
    v4.display();
    return 0;
}