#include <iostream>
#include <string>

using namespace std;

class Car {
public:
    string make;
    string model;

    void set_year(int y) {
        if (y < 1885) {
            cout << "Invalid year. The year cannot be earlier than 1885." << endl;
        } else {
            year = y;
        }
    }

    int get_year() {
        return year;
    }

    void printDetails() {
        cout << "Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }

private:
    int year;
};

int main(void) {
    Car myCar;
    myCar.make = "Toyota";
    myCar.model = "Corolla";
    myCar.set_year(2010);
    myCar.set_year(2022);
    myCar.set_year(1800);
    myCar.printDetails();

    return 0;
}
