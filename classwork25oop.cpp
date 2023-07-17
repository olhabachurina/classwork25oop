// classwork25oop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include "Employee.h"
using namespace std;

int main()
{
    std::string filePath = "employees.txt";
    std::ofstream file(filePath, std::ios::app);

    if (!file) {
        std::cout << "Error opening the file." << std::endl;
        return 1;
    }

    while (true) {
        std::string firstName, lastName, position;
        double salary;

        try {
            std::cout << "Enter First Name: ";
            std::cin >> firstName;

            std::cout << "Enter Last Name: ";
            std::cin >> lastName;

            std::cout << "Enter Position: ";
            std::cin >> position;

            std::cout << "Enter Salary: ";
            std::cin >> salary;

            Employee employee(firstName, lastName, position, salary);
            employee.saveToFile(file);
        }
        catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << std::endl;
            continue;
        }

        char choice;
        std::cout << "Do you want to add another employee? (y/n): ";
        std::cin >> choice;

        if (choice != 'y' && choice != 'Y') {
            break;
        }
    }

    file.close();
    std::cout << "Employee information has been saved to the file." << std::endl;

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
