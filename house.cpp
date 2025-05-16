#include <iostream>
#include <string>
#include <vector>

using namespace std;

// -------------------
// Appliance Class
// -------------------
class Appliance {
private:
    string m_name;
    string m_model; // Optional model number

public:
    Appliance(string name, string model = "N/A") : m_name(name), m_model(model) {
        cout << "Appliance '" << m_name << "' created." << endl;
    }

    ~Appliance() {
        cout << "Appliance '" << m_name << "' destroyed." << endl;
    }

    string getName() const {
        return m_name;
    }

    string getModel() const {
        return m_model;
    }

    void printInfo() const {
        cout << "Appliance: " << m_name << ", Model: " << m_model << endl;
    }
};

// -------------------
// House Class
// -------------------
class House {
private:
    string m_address;
    vector<Appliance*> m_appliances; // Aggregation: House has appliances, but doesn't own them

public:
    House(string address) : m_address(address) {
        cout << "House at '" << m_address << "' created." << endl;
    }

    ~House() {
        cout << "House at '" << m_address << "' destroyed." << endl;
        // Note: We DO NOT delete the appliances here because the House does not own them.
        // The appliances' lifetimes are managed externally.
    }

    void addAppliance(Appliance* appliance) {
        m_appliances.push_back(appliance);
        cout << "Appliance '" << appliance->getName() << "' added to the house." << endl;
    }

    void removeAppliance(Appliance* appliance) {
        // Find the appliance in the vector and remove it
        for (size_t i = 0; i < m_appliances.size(); ++i) {
            if (m_appliances[i] == appliance) {
                m_appliances.erase(m_appliances.begin() + i);
                cout << "Appliance '" << appliance->getName() << "' removed from the house." << endl;
                return; // Exit once found and removed
            }
        }
        cout << "Appliance not found in the house." << endl;
    }

    void listAppliances() const {
        cout << "Appliances in the house:" << endl;
        for (const auto* appliance : m_appliances) {
            cout << "- " << appliance->getName() << endl;
        }
    }

    void printAllAppliancesInfo() const {
        cout << "Appliance details in the house:" << endl;
        for (const auto* appliance : m_appliances) {
            appliance->printInfo();
        }
    }
};

// -------------------
// Main Function
// -------------------
int main() {
    // Create appliances independently
    Appliance* fridge = new Appliance("Refrigerator", "Model-X100");
    Appliance* tv = new Appliance("Television", "SmartTV-5000");
    Appliance* oven = new Appliance("Oven", "SuperBake-2024");

    // Create a house
    House myHouse("123 Main St");

    // Add appliances to the house
    myHouse.addAppliance(fridge);
    myHouse.addAppliance(tv);
    myHouse.addAppliance(oven);

    // Print all appliance info through the house
    myHouse.printAllAppliancesInfo();
    cout << endl;

    // Remove the TV from the house
    myHouse.removeAppliance(tv);

    // Print all appliance info again to show the remaining appliances
    myHouse.printAllAppliancesInfo();
    cout << endl;

    // Demonstrate that the removed TV still exists and functions
    cout << "The TV still exists:" << endl;
    tv->printInfo(); // Still prints the TV's info because it hasn't been deleted
    cout << endl;

    // Clean up memory (demonstration purpose; smart pointers recommended for real-world use)
    delete fridge;
    delete tv;
    delete oven;

    return 0;
}
