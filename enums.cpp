#include <iostream>

enum GameMode {
    Easy = 1,
    Medium = 25,
    Hard = 30
};

int main() {
    GameMode mode = Medium;

    switch (mode) {
        case Easy:
            std::cout << "Selected mode: Easy" << std::endl;
            std::cout << "Good luck! The enemies will be easy to defeat." << std::endl;
            break;
        case Medium:
            std::cout << "Selected mode: Medium" << std::endl;
            std::cout << "Good luck! The enemies will be " << Medium << " times more challenging than easy!" << std::endl;
            break;
        case Hard:
            std::cout << "Selected mode: Hard" << std::endl;
            std::cout << "Good luck! The enemies will be " << Hard << " times more challenging than easy!" << std::endl;
            break;
    }

    return 0;
}
