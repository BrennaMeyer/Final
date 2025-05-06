// Final.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer: Brenna Meyer
// Date:05/06/2025
//Requirements: Write a modular program that asks the user for a file name. Assume the file contains a series of numbers, each written on a separate line. The program should read the contents of the file into an array then display the following data:
//• The lowest number in the array
//• The highest number in the array
//• The total of the numbers in the array
//• The average of the numbers in the array
//To test the program, you can download the file numbers.txt or ListOfNumbers.txt
//You may also want to create your own file with something funky in it to see how
//well your code handles it.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

//File Reader
vector<double> readNumFromFile(const string& fileName) {
    ifstream inputFile(fileName);
    vector<double> numbers;

    cout << "attempting to open:" << fileName << endl;

    if (!inputFile.is_open()) {
        cout << "Error File could not open" << fileName << endl;
        return numbers;

    }
    double number;
    while (inputFile >> number) {
        numbers.push_back(number);
    }

    //Error Check
    if (inputFile.fail() && !inputFile.eof()) {
        cout << "Warning file does not contain numeric data." << endl;
    }
    cout << "File could be read" << numbers.size() << endl;
    inputFile.close();
    return numbers;
}
//Minium value vector 
double findMin(const vector<double>& numbers) {
    double min =
        numeric_limits<double>::max();

    for (double num : numbers) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}
//Maxium Value
double findMax(const vector<double>& numbers) {
    double max =
        numeric_limits<double>::lowest();
    for (double num : numbers) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

//total 
double calculateTotal(const vector<double>& numbers) {
    double total = 0.0;

    for (double num : numbers) {
        total += num;
    }
    return total;
}

// Average 
double calculateAve(const vector<double>& numbers) {
    if (numbers.empty()) {
        return 0.0;
    }
    return calculateTotal(numbers) / numbers.size();
}

//Results
void displayResults(double min, double max, double total, double average) {
    cout << fixed << setprecision(2);
    cout << "Statisic Results:" << endl;
    cout << "Minimum Number:" << min << endl;
    cout << "Maximum Number:" << max << endl;
    cout << "Total:" << total << endl;
    cout << "Average:" << average << endl;
}
int main()
{
    cout << "Number File Statistics Program" << endl;

    //File Name
    string fileName;
    cout << "Enter File Name (numbers.txt):"; 
    getline (cin, fileName);

    //Read Numbers from file 
    vector<double> numbers = readNumFromFile(fileName);

    if (numbers.empty()) {
        cout << "Error there are no vaild numbers found in the file." << endl;
        return 1;
    }

    //Statisitcs 
    double min = findMin(numbers);
    double max = findMax(numbers);
    double total = calculateTotal(numbers);
    double average = calculateAve(numbers);

    //Results 
    displayResults(min, max, total, average);
    return 0;
}

