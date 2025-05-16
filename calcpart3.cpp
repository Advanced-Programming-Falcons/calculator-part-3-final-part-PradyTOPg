#include <iostream>
#include <string>
#include <vector>
#include <cctype> // for input validation

class Calculator {
private:
    std::vector<std::string> history_; // history

public:
    Calculator() {}

    bool isValidInput(const std::string& input) {
        char op;
        double num1, num2;

        if (sscanf(input.c_str(), "%lf %c %lf", &num1, &op, &num2) != 3) {
            std::cerr << "Error: Invalid input format!" << std::endl;
            return false;
        }

        if (op != '+' && op != '-' && op != '*' && op != '/') {
            std::cerr << "Error: Invalid operator!" << std::endl;
            return false;
        }

        return true;
    }

    double calculate(const std::string& input) {
        double num1, num2;
        char op;

       
        sscanf(input.c_str(), "%lf %c %lf", &num1, &op, &num2);

        switch (op) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                if (num2 != 0) {
                    return num1 / num2;
                } else {
                    std::cerr << "Error: Division by zero!" << std::endl;
                    return 0.0;
                }
            default:
                std::cerr << "Error: Invalid operator!" << std::endl;
                return 0.0;
        }
    }
    void addHistory(const std::string& calculation) {
        history_.push_back(calculation);
    }

 
    void displayHistory() {
        for (const auto& entry : history_) {
            std::cout << entry << std::endl;
        }
    }
};

int main() {
    Calculator calc;
    std::string input;

    while (true) {
        std::cout << "Enter calculation (e.g., 2+2): ";
        std::getline(std::cin, input);

        if (!calc.isValidInput(input)) {
            continue;
        }

        double result = calc.calculate(input);
        std::cout << "Result: " << result << std::endl;

        calc.addHistory(input + " = " + std::to_string(result));
        calc.displayHistory();
    }

    return 0;
}
