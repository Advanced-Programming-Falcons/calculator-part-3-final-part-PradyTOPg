#include <iostream>
#include <string>

using namespace std;

class Car { 
public: 
    string make;
    string model;
    int year;
    float price;
};

int main(void) {
    cout << "Car Information" << endl;

    Car car1; 
    car1.make = "Toyota";
    car1.model = "Camry";
    car1.year = 2020;
    car1.price = 24000.50;

    Car car2; 
    car2.make = "Honda";
    car2.model = "Civic";
    car2.year = 2021;
    car2.price = 22000.75;

    cout << "Car 1: " << car1.year << " " << car1.make << " " << car1.model << " costs $" << car1.price << endl;
    cout << "Car 2: " << car2.year << " " << car2.make << " " << car2.model << " costs $" << car2.price << endl;

    return 0;
}
