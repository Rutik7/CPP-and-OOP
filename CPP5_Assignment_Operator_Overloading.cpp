#include <iostream>
using namespace std;

class Number {
private:
    int value;

public:
    // Constructor
    Number(int v = 0) : value(v) {}

    // Overload assignment operator
    Number& operator=(const Number& obj) {
        if (this != &obj) {  // Avoid self-assignment
            value = obj.value;
        }
        return *this;  // Return current object to allow chained assignments
    }

    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number n1(10);
    Number n2;

    n2 = n1;  // Calls overloaded assignment operator

    n2.display();  // Output: Value: 10

    return 0;
}