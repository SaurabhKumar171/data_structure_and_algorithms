// Define a structure Point with fields x and y. Write a program to sort an array of points based on their distance from the origin (0, 0). If two points have the same distance, sort them by their x-coordinate

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Define the Student class
class Point {
public:
    int x;
    int y;

    // Constructor with member initializer list
    Point(int x1, int y1) : x(x1), y(y1) {}
};

bool customComparator(const Point& s1 , const Point& s2){

    int squaredDistacnce1 = s1.x*s1.x  + s1.y*s1.y;
    int squaredDistacnce2 = s2.x*s2.x  + s2.y*s2.y;
    
    if(squaredDistacnce1 == squaredDistacnce2){

        if(s1.x == s2.x){
            return s1.y < s2.y;
        }

        return s1.x < s2.x;
    }

    return squaredDistacnce1 < squaredDistacnce2;
}

int main() {
    vector<Point> points = {{3, 4}, {1, 1}, {0, 5}, {2, 2}, {0, 0} };
    
    // Sort students using the custom comparator
    sort(points.begin(), points.end(), customComparator);
    
    // Output the sorted array
    cout << "Sorted array is:\n";
    for (const Point& s : points) {
        cout << s.x << ", " << s.y << endl;
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.