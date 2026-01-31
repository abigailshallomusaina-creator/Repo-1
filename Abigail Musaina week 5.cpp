#include <iostream>
using namespace std; 
struct Fraction {
    int num;
    int den;
};

const Fraction& findLargest(const Fraction& f1, const Fraction& f2, const Fraction& f3) {
    
    const Fraction* winner = &f1;

    if (f2.num * winner->den > winner->num * f2.den) {
        winner = &f2;
    }

    if (f3.num * winner->den > winner->num * f3.den) {
        winner = &f3;
    }

    return *winner; 
}

int main() {
    Fraction fract1 = {1, 3}; 
    Fraction fract2 = {3, 4}; 
    Fraction fract3 = {2, 5}; 

   
    const Fraction& largest = findLargest(fract1, fract2, fract3);

   
    cout << "The largest fraction is: " << largest.num << "/" << largest.den << endl;

    return 0;
}