#include <iostream>
#include <string>

using namespace std;

// --- BASE CLASS ---
class Employee {
protected:
    string firstName;
    string lastName;

public:
    // Constructor
    Employee(string f, string l) : firstName(f), lastName(l) {}

    // Virtual Destructor
    virtual ~Employee() {}

    // Pure Virtual Function (makes this an Abstract Class)
    virtual double calculateSalary() = 0;

    void display() {
        cout << "Employee: " << firstName << " " << lastName << endl;
    }
};

// --- DERIVED CLASS 1: SALARY ---
class SalaryEmployee : public Employee {
private:
    double monthlySalary;

public:
    SalaryEmployee(string f, string l, double sal) 
        : Employee(f, l), monthlySalary(sal) {}

    // Implementation of the pure virtual function
    double calculateSalary() override {
        return monthlySalary;
    }
};

// --- DERIVED CLASS 2: HOURLY ---
class HourlyEmployee : public Employee {
private:
    double hourlyRate;
    double hoursWorked;

public:
    HourlyEmployee(string f, string l, double rate, double hours) 
        : Employee(f, l), hourlyRate(rate), hoursWorked(hours) {}

    // Implementation of the pure virtual function
    double calculateSalary() override {
        return hourlyRate * hoursWorked;
    }
};


int main() {
    // Using pointers to demonstrate Polymorphism
    Employee* e1 = new SalaryEmployee("Jones", "kiharie", 10000.00);
    Employee* e2 = new HourlyEmployee("mary", "kanye", 50.0, 360.0);

    cout << "--- Payroll Processing ---" << endl;

    e1.display();
    cout << e1.calculateSalary() << endl << endl;

    e2.display();
    cout  << e2.calculateSalary() << endl;

    // Clean up memory
    delete e1;
    delete e2;

    return 0;
}