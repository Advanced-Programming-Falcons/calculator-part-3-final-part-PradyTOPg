#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int choice;
    float num1, num2, result;
    vector<string> history;
    while (true) {
        cout << "Simple Calculator" << endl;
        cout << "1. Addition" << endl;
        cout << "2. Subtraction" << endl;
        cout << "3. Multiplication" << endl;
        cout << "4. Division" << endl;
        cout << "5. Power" << endl;
        cout << "6. Root" << endl; 
        cout << "7. History" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter choice (1-8): ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        if (choice == 1) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 + num2;
            cout << "Result: " << result << endl;
            history.push_back("Added " + to_string(num1) + " and " + to_string(num2) + " = " + to_string(result));
        } else if (choice == 2) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 - num2;
            cout << "Result: " << result << endl;
            history.push_back("Subtracted " + to_string(num2) + " from " + to_string(num1) + " = " + to_string(result));
        } else if (choice == 3) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            result = num1 * num2;
            cout << "Result: " << result << endl;
            history.push_back("Multiplied " + to_string(num1) + " and " + to_string(num2) + " = " + to_string(result));
        } else if (choice == 4) {
            cout << "Enter two numbers: ";
            cin >> num1 >> num2;
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
                history.push_back("Divided " + to_string(num1) + " by " + to_string(num2) + " = " + to_string(result));
            } else {
                cout << "Error: Division by zero!" << endl;
            }
        } else if (choice == 5) {
            cout << "Enter base and exponent: ";
            cin >> num1 >> num2;
            result = pow(num1, num2);
            cout << "Result: " << result << endl;
            history.push_back("Raised " + to_string(num1) + " to the power of " + to_string(num2) + " = " + to_string(result));
        } else if (choice == 6) {
            cout << "Enter number and root: ";
            cin >> num1 >> num2;
            result = pow(num1, 1.0 / num2);
            cout << "Result: " << result << endl;
            history.push_back("Took the " + to_string(num2) + " root of " + to_string(num1) + " = " + to_string(result));
        } else if (choice == 7) {
            for (int i = 0; i < history.size(); i++) {
                cout << history[i] << endl;
            }
        } else if (choice == 8) {
            break;
        }
    }
    return 0;
}
