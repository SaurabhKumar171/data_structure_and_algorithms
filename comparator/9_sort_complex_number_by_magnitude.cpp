//Define a structure Complex with fields real and imaginary. Sort a list of complex numbers based on their magnitude (square root of the sum of the squares of the real and imaginary parts). If two complex numbers have the same magnitude, sort them by their real part
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define the Student class
class Complex {
public:
    int real;
    int imaginary;

    // Constructor with member initializer list
    Complex(int r, int i) : real(r), imaginary(i) {}
};

bool customComparator(const Complex& s1 , const Complex& s2){

    int magnitude1 = s1.real*s1.real  + s1.imaginary*s1.imaginary;
    int magnitude2 = s2.real*s2.real  + s2.imaginary*s2.imaginary;
    
    if(magnitude1 == magnitude2){

        if(s1.real == s2.real){
            return s1.imaginary < s2.imaginary;
        }

        return s1.real < s2.real;
    }

    return magnitude1 < magnitude2;
}    

int main() {
    vector<Complex> complexs = {
    {3, 4}, 
    {1, 1},    
    {0, 5},   
    {2, -2}, 
    {-3, -4} 
};
    
    // Sort students using the custom comparator
    sort(complexs.begin(), complexs.end(), customComparator);
    
    // Output the sorted array
    cout << "Sorted array is:\n";
    for (const Complex& s : complexs) {
        cout << s.real << ", " << s.imaginary << endl;
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.