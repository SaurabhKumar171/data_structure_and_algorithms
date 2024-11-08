// Sort Students by Name and Age
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define the Student class
class Student {
public:
    string name;
    int age;

    // Constructor with member initializer list
    Student(string n, int a) : name(n), age(a) {}
};

bool customComparator(const Student& s1 , const Student& s2){

    if(s1.name < s2.name) return true;
    else if(s1.name == s2.name) return s1.age < s2.age;

    return false;
}

int main() {
    vector<Student> students = {
        {"John", 22},
        {"Alice", 21},
        {"Bob", 25},
        {"Alice", 19},
        {"John", 20}
    };
    
    // Sort students using the custom comparator
    sort(students.begin(), students.end(), customComparator);
    
    // Output the sorted array
    cout << "Sorted array is:\n";
    for (const Student& s : students) {
        cout << s.name << ", " << s.age << endl;
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.