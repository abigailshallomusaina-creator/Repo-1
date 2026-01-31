#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int age;
    int serviceYear;
    double salary;

public:

    Employee(string n, int a, int s, double sal) {
        name = n;
        age = a;
        serviceYear = s;
        salary = sal;
    
    }

    // Destructor
    ~Employee() {
        cout << "object destroyed"<< endl;
    }

    // Accessor Member Functions
    string getName() { return name; }
    int getAge() { return age; }
    int getServiceYear() { return serviceYear; }
    double getSalary() { return salary; }
};

int main() {
    // Initializing the object
    Employee emp("Abigail", 45, 2025, 85000.00);

    // Displaying the output
    cout << "\nEmployee Name: " << emp.getName() << endl;
    cout << "Employee Age: " << emp.getAge() << endl;
    cout << "Service Years: " << emp.getServiceYear() << endl;
    cout << "Monthly Salary: " << emp.getSalary() << endl << endl;

    return 0;
}