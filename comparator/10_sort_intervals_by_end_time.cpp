
// Given an array of intervals (pairs of start and end times), sort them by their end time. If two intervals have the same end time, sort by their start time
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// bool customComparator(const pair<int,int>& s1 , const pair<int,int>& s2){
//     if(s2.second == s1.second){
//         return s1.first < s2.first;
//     }

//     return s1.second < s2.second;
// }

int main() {
    vector<pair<int,int>> intervals = {
    {3, 4}, 
    {1, 1},    
    {0, 5},   
    {2, -2}, 
    {-3, -4} 
};
    
    // Sort students using the custom comparator
    sort(intervals.begin(), intervals.end(), [](const pair<int,int>& s1 , const pair<int,int>& s2){  //:Lambda function
    if(s2.second == s1.second){
        return s1.first < s2.first;
    }

    return s1.second < s2.second;
});
    
    // Output the sorted array
    cout << "Sorted array is:\n";
    for (const auto &interval : intervals) {
        std::cout << "{" << interval.first << ", " << interval.second << "}\n";
    }

    return 0;
}



// NOTE : if comparator returns true then first no. will come first else second no.