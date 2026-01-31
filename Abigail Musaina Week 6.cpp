#include <iostream>

using namespace std;

int main() {
    int original[20];
    int even[20];
    int odd[20];
    
    int evenIndex = 0;
    int oddIndex = 0;


    for (int i = 0; i < 20; i++) {
        original[i] = (rand() % 100) + 1; 

        if (original[i] % 2 == 0) {
            even[evenIndex] = original[i];
            evenIndex++;
        } else {
            odd[oddIndex] = original[i];
            oddIndex++;
        }
    }

    
    cout << "Original: ";
    for (int i = 0; i < 20; i++) cout << original[i] << " ";

    cout << "\nEven: ";
    for (int i = 0; i < evenIndex; i++) cout << even[i] << " ";

    cout << "\nOdd: ";
    for (int i = 0; i < oddIndex; i++) cout << odd[i] << " ";

    return 0;
}