#include "Employee.h"
Employee::Employee(const std::string& firstName, const std::string& lastName, const std::string& position, double salary)
    : firstName(firstName), lastName(lastName), position(position), salary(salary) {}

std::string Employee::getFirstName() const {
    return firstName;
}

void Employee::setFirstName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("First name cannot be empty.");
    }
    firstName = name;
}

std::string Employee::getLastName() const {
    return lastName;
}

void Employee::setLastName(const std::string& name) {
    if (name.empty()) {
        throw std::invalid_argument("Last name cannot be empty.");
    }
    lastName = name;
}

std::string Employee::getPosition() const {
    return position;
}

void Employee::setPosition(const std::string& pos) {
    if (pos.empty()) {
        throw std::invalid_argument("Position cannot be empty.");
    }
    position = pos;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double sal) {
    if (sal <= 0) {
        throw std::invalid_argument("Salary should be a positive number.");
    }
    salary = sal;
}

void Employee::saveToFile(std::ofstream& file) const {
    file << "First Name: " << firstName << std::endl;
    file << "Last Name: " << lastName << std::endl;
    file << "Position: " << position << std::endl;
    file << "Salary: " << salary << std::endl;
    file << "-------------------" << std::endl;
}