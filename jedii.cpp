#include <iostream>
#include <string>

class Jedi {
public:
    std::string name;
    int age;
    std::string lightsaberColor;

    Jedi() : name("Unknown"), age(0), lightsaberColor("Blue"), rank("Padawan"), darkside(false) {
        std::cout << "Default constructor called\n";
    }

    Jedi(std::string n, int a, std::string r, std::string lColor, bool ds)
        : name(n), age(a), lightsaberColor(lColor), darkside(ds) {
        setRank(r);
        std::cout << "Parameterized constructor called for " << name << "\n";
    }

    void setRank(const std::string& r) {
        if (r == "Padawan" || r == "Knight" || r == "Master") {
            rank = r;
        } else {
            std::cout << "Invalid rank.\n";
        }
    }

    void setDarkSide(bool ds) {
        darkside = ds;
    }

    void printInfo() const {
        std::cout << "Name: " << name 
                  << " Age: " << age 
                  << " Rank: " << rank 
                  << " Lightsaber Color: " << lightsaberColor 
                  << " Dark Side: " << (darkside ? "Yes" : "No") 
                  << std::endl;
    }

private:
    std::string rank;
    bool darkside;
};

int main() {
    Jedi jedi1;
    Jedi jedi2("Anakin Skywalker", 22, "Knight", "Blue", false);

    jedi1.printInfo();
    jedi2.printInfo();

    jedi1.setRank("Master");
    jedi2.setDarkSide(true);

    std::cout << "\nAfter changes:\n";
    jedi1.printInfo();
    jedi2.printInfo();

    return 0;
}
