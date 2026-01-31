#include <iostream>

using namespace std;

// Base Class
class Square {
protected:
    double side;

public:
    // Parameterized Constructor
    Square(double s) {
        side = s;
        cout << "Square created with side: " << side << endl;
    }

    // Virtual Destructor for proper cleanup in inheritance
    virtual ~Square() {
        cout << "Square destroyed." << endl;
    }

    // Function for Square Area
    double getArea() {
        return side * side;
    }

    // Function for Square Perimeter
    double getPeri() {
        return 4 * side;
    }
};

// Derived Class
class Cube : public Square {
public:
    // Constructor passes 's' to the Square constructor
    Cube(double s) : Square(s) {
        cout << "Cube created." << endl;
    }

    // Destructor
    ~Cube() {
        cout << "Cube destroyed." << endl;
    }

    // Surface Area of a Cube: 6 * side^2
    double getArea() {
        return 6 * (side * side);
    }

    // Volume of a Cube: side^3
    double getVolume() {
        return side * side * side;
    }
};

int main() {
    // Creating a Cube object with side length 5
    double val = 5.0;
    Cube myCube(val);

    cout << "\n--- Results for Cube with side " << val << " ---" << endl;
    cout << "Surface Area: " << myCube.getArea() << endl;   
    cout << "Volume:       " << myCube.getVolume() << endl; 
    cout << "--------------------------------------\n" << endl;

    return 0;
}