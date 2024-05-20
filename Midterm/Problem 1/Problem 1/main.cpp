//
//  main.cpp
//  Problem 1

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    string name, gender;
    int age, heightFeet, heightInches, weightPounds;
    double heightInInches, bmi;

    // Ask the user questions and input responses
    cout << "Please enter your name: ";
    getline(cin, name); // Use getline to handle spaces in the name
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your gender (male/female): ";
    cin >> gender;
    cout << "Please enter your height in feet: ";
    cin >> heightFeet;
    cout << "Please enter your height in inches: ";
    cin >> heightInches;
    cout << "Please enter your weight in pounds: ";
    cin >> weightPounds;

    // Process the responses
    heightInInches = (heightFeet * 12) + heightInches;
    bmi = 703 * weightPounds / (heightInInches * heightInInches);

    // Determine BMI status
    string bmiStatus;
    if (bmi < 18.5) {
        bmiStatus = "underweight";
    } else if (bmi >= 18.5 && bmi < 24.9) {
        bmiStatus = "normal weight";
    } else if (bmi >= 25 && bmi < 29.9) {
        bmiStatus = "overweight";
    } else {
        bmiStatus = "obese";
    }

    // Output the results
    cout << fixed << setprecision(1); // Set precision for BMI output
    cout << "\nHi " << name << ",\n";
    cout << "You are a " << gender << ". You are " << age << " years old. You are currently "
         << heightFeet << "'" << heightInches << "\" and you currently weigh " << weightPounds
         << " pounds. Your BMI is " << bmi << ", which is " << bmiStatus << ".\n";
    cout << "Thank you for using the BMI Calculator!" << endl;

    return 0;
}

