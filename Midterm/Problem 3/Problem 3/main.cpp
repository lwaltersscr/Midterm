#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <cctype>

using namespace std;

// Function to perform basic arithmetic operations
void performBasicOperation(char operation, double num1, double num2) {
    switch (operation) {
        case '+':
            cout << "Result: " << num1 + num2 << endl;
            break;
        case '-':
            cout << "Result: " << num1 - num2 << endl;
            break;
        case '*':
            cout << "Result: " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 != 0)
                cout << "Result: " << num1 / num2 << endl;
            else
                cout << "Error: Division by zero" << endl;
            break;
        case '%':
            if (static_cast<int>(num2) != 0)
                cout << "Result: " << static_cast<int>(num1) % static_cast<int>(num2) << endl;
            else
                cout << "Error: Modulus by zero" << endl;
            break;
        case '^':
            cout << "Result: " << pow(num1, num2) << endl;
            break;
        default:
            cout << "Invalid operation" << endl;
            break;
    }
}

// Function to perform single-argument mathematical functions
void performFunctionOperation(const string& operation, double num) {
    if (operation == "sin") {
        cout << "Result: " << sin(num) << endl;
    } else if (operation == "asin") {
        cout << "Result: " << asin(num) << endl;
    } else if (operation == "cos") {
        cout << "Result: " << cos(num) << endl;
    } else if (operation == "acos") {
        cout << "Result: " << acos(num) << endl;
    } else if (operation == "tan") {
        cout << "Result: " << tan(num) << endl;
    } else if (operation == "atan") {
        cout << "Result: " << atan(num) << endl;
    } else if (operation == "sqrt") {
        if (num >= 0) {
            cout << "Result: " << sqrt(num) << endl;
        } else {
            cout << "Error: Square root of negative number" << endl;
        }
    } else if (operation == "ceil") {
        cout << "Result: " << ceil(num) << endl;
    } else if (operation == "abs") {
        cout << "Result: " << abs(num) << endl;
    } else if (operation == "floor") {
        cout << "Result: " << floor(num) << endl;
    } else if (operation == "log") {
        if (num > 0) {
            cout << "Result: " << log(num) << endl;
        } else {
            cout << "Error: Logarithm of non-positive number" << endl;
        }
    } else if (operation == "log10") {
        if (num > 0) {
            cout << "Result: " << log10(num) << endl;
        } else {
            cout << "Error: Logarithm of non-positive number" << endl;
        }
    } else if (operation == "log2") {
        if (num > 0) {
            cout << "Result: " << log2(num) << endl;
        } else {
            cout << "Error: Logarithm of non-positive number" << endl;
        }
    } else if (operation == "round") {
        cout << "Result: " << round(num) << endl;
    } else {
        cout << "Invalid function operation" << endl;
    }
}

// Function to perform two-argument mathematical functions
void performFunctionOperation2(const string& operation, double num1, double num2) {
    if (operation == "atan2") {
        cout << "Result: " << atan2(num1, num2) << endl;
    } else if (operation == "max") {
        cout << "Result: " << max(num1, num2) << endl;
    } else if (operation == "min") {
        cout << "Result: " << min(num1, num2) << endl;
    } else {
        cout << "Invalid function operation" << endl;
    }
}

int main() {
    string input, repeat;

    do {
        // Prompt user to enter the equation
        cout << "Enter the problem to solve (e.g., 3+5, sin(0.5), max(3,5)): ";
        getline(cin, input);

        // Remove spaces from the input for easier parsing
        input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

        // Check for basic operations
        size_t pos;
        char operation;
        if ((pos = input.find('+')) != string::npos) {
            operation = '+';
        } else if ((pos = input.find('-')) != string::npos) {
            operation = '-';
        } else if ((pos = input.find('*')) != string::npos) {
            operation = '*';
        } else if ((pos = input.find('/')) != string::npos) {
            operation = '/';
        } else if ((pos = input.find('%')) != string::npos) {
            operation = '%';
        } else if ((pos = input.find('^')) != string::npos) {
            operation = '^';
        } else {
            operation = '\0';
        }

        if (operation != '\0') {
            // Extract operands and perform basic operation
            double num1 = stod(input.substr(0, pos));
            double num2 = stod(input.substr(pos + 1));
            performBasicOperation(operation, num1, num2);
        } else {
            // Check for function operations
            if (input.find("atan2") != string::npos) {
                // Extract and perform atan2 operation
                size_t start = input.find('(');
                size_t comma = input.find(',');
                size_t end = input.find(')');
                double num1 = stod(input.substr(start + 1, comma - start - 1));
                double num2 = stod(input.substr(comma + 1, end - comma - 1));
                performFunctionOperation2("atan2", num1, num2);
            } else if (input.find("max") != string::npos || input.find("min") != string::npos) {
                // Extract and perform max/min operation
                string operation = input.substr(0, 3);
                size_t start = input.find('(');
                size_t comma = input.find(',');
                size_t end = input.find(')');
                double num1 = stod(input.substr(start + 1, comma - start - 1));
                double num2 = stod(input.substr(comma + 1, end - comma - 1));
                performFunctionOperation2(operation, num1, num2);
            } else {
                // Extract and perform single-argument function operation
                string operation = input.substr(0, input.find('('));
                size_t start = input.find('(');
                size_t end = input.find(')');
                double num = stod(input.substr(start + 1, end - start - 1));
                performFunctionOperation(operation, num);
            }
        }

        // Prompt user to solve another problem or exit
        cout << "Would you like to solve another problem? (y/n): ";
        cin >> repeat;
        cin.ignore(); // Ignore the newline character left in the input buffer
    } while (repeat == "y" || repeat == "Y");

    cout << "Thanks for using the calculator!" << endl;

    return 0;
}
