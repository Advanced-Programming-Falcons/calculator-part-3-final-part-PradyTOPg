#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Car {
private:
    string make;
    string model;
    int year;
    int miles;
    double price;

public:
    // Default constructor
    Car() : make(""), model(""), year(0), miles(0), price(0.0) {}

    // Parameterized constructor
    Car(string carMake, string carModel, int carYear, int carMiles, double carPrice)
        : make(carMake), model(carModel), year(carYear), miles(carMiles), price(carPrice) {}

    // Destructor
    ~Car() {
        cout << "A car has been sold/removed from the inventory: " << make << " " << model << endl;
    }

    // Setters
    void setMake(string carMake) { make = carMake; }
    void setModel(string carModel) { model = carModel; }
    void setYear(int carYear) { year = carYear; }
    void setMiles(int carMiles) { miles = carMiles; }
    void setPrice(double carPrice) { price = carPrice; }

    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    int getMiles() const { return miles; }
    double getPrice() const { return price; }

    // Display car details
    void displayCar() const {
        cout << year << " " << make << " " << model << " | Miles: " << miles << " | Price: $" << price << endl;
    }
};

// Function declarations
void displayMenu();
void addCar(vector<Car>& inventory);
void removeCar(vector<Car>& inventory);
void updateCar(vector<Car>& inventory);
void displayInventory(const vector<Car>& inventory);

int main() {
    vector<Car> inventory;

    // Pre-populating inventory with some cars
    inventory.push_back(Car("Toyota", "Camry", 2020, 30000, 20000));
    inventory.push_back(Car("Honda", "Civic", 2019, 20000, 18000));

    int choice;

    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            addCar(inventory);
            break;
        case 2:
            removeCar(inventory);
            break;
        case 3:
            updateCar(inventory);
            break;
        case 4:
            displayInventory(inventory);
            break;
        case 5:
            cout << "Exiting the program. Thank you for using the Used Car Dealer System!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\nWelcome to the Used Car Dealer System" << endl;
    cout << "1. Add a new car" << endl;
    cout << "2. Remove a car" << endl;
    cout << "3. Update car information" << endl;
    cout << "4. Display inventory" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addCar(vector<Car>& inventory) {
    if (inventory.size() >= 15) {
        cout << "Inventory is full. Cannot add more cars." << endl;
        return;
    }

    string make, model;
    int year, miles;
    double price;

    cout << "Enter car make: ";
    cin >> make;
    cout << "Enter car model: ";
    cin >> model;
    cout << "Enter car year: ";
    cin >> year;
    cout << "Enter car miles: ";
    cin >> miles;
    cout << "Enter car price: ";
    cin >> price;

    inventory.push_back(Car(make, model, year, miles, price));
    cout << "Car added successfully." << endl;
}

void removeCar(vector<Car>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty. No cars to remove." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the car to remove (0 to " << inventory.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < inventory.size()) {
        inventory.erase(inventory.begin() + index);
        cout << "Car removed successfully." << endl;
    } else {
        cout << "Invalid index. No car removed." << endl;
    }
}

void updateCar(vector<Car>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty. No cars to update." << endl;
        return;
    }

    int index;
    cout << "Enter the index of the car to update (0 to " << inventory.size() - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < inventory.size()) {
        string make, model;
        int year, miles;
        double price;

        cout << "Enter new car make: ";
        cin >> make;
        cout << "Enter new car model: ";
        cin >> model;
        cout << "Enter new car year: ";
        cin >> year;
        cout << "Enter new car miles: ";
        cin >> miles;
        cout << "Enter new car price: ";
        cin >> price;

        inventory[index].setMake(make);
        inventory[index].setModel(model);
        inventory[index].setYear(year);
        inventory[index].setMiles(miles);
        inventory[index].setPrice(price);

        cout << "Car updated successfully." << endl;
    } else {
        cout << "Invalid index. No car updated." << endl;
    }
}

void displayInventory(const vector<Car>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty." << endl;
        return;
    }

    cout << "\nCurrent Inventory:" << endl;
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "Index " << i << ": ";
        inventory[i].displayCar();
    }
}

