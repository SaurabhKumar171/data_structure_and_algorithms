// Define a structure Employee with fields name (string) and salary (int). Sort the employees by salary in descending order. If two employees have the same salary, sort them alphabetically by name
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define the Student class
class Employee {
public:
    string name;
    int salary;

    // Constructor with member initializer list
    Employee(string n, int s) : name(n), salary(s) {}
};

bool customComparator(const Employee& s1 , const Employee& s2){
    
    if(s1.salary == s2.salary) return s1.name < s2.name;

    return s1.salary > s2.salary;
}

int main() {
    vector<Employee> employees = {
        {"Alice", 50000},
        {"Bob", 70000},
        {"Charlie", 70000},
        {"David", 50000},
        {"Eve", 60000}
    };
    
    // Sort students using the custom comparator
    sort(employees.begin(), employees.end(), customComparator);
    
    // Output the sorted array
    cout << "Sorted array is:\n";
    for (const Employee& s : employees) {
        cout << s.name << ", " << s.salary << endl;
    }

    return 0;
}

// NOTE : if comparator returns true then first no. will come first else second no.