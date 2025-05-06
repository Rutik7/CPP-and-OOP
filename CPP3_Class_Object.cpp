#include <iostream>
#include <string>

class Car {
private:
    std::string make;  
    std::string model; 
    int year;          

public:
    // Constructor to initialize the car object
    Car(std::string m, std::string mod, int y) : make(m), model(mod), year(y) 
    {

    }

    
    void displayDetails() const {
        std::cout << "Car Make: " << make << std::endl;
        std::cout << "Car Model: " << model << std::endl;
        std::cout << "Year of Manufacture: " << year << std::endl;
        //year = 1000;
    }

    
    void updateYear(int newYear) {
        year = newYear;
    }
};

int main() {
    // Create an object of the Car class
    Car myCar("Toyota", "Camry",2004);

    // Display the details of the car
    myCar.displayDetails();

    // Update the year of the car
    myCar.updateYear(2021);

    // Display the updated details of the car
    std::cout << "\nAfter updating the year:\n";
    myCar.displayDetails();

    return 0;
}