#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// Brute force solution
vector<vector<int>> merge(vector<vector<int>>& intervals) {

    int row = intervals.size();
    int col = intervals[0].size();

    if(intervals.size() <= 1){
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    vector<bool> mergedFlags(intervals.size(), false);

    for(int i = 0; i < intervals.size() ; i++){

        if (mergedFlags[i]) continue;

        int first = intervals[i][0];
        int second = intervals[i][1];

        for(int j = i+1; j < intervals.size(); j++){                
            if(second >= intervals[j][0]){
                second = max(second, intervals[j][1]);

                mergedFlags[j] = true;
            }
        } 
        res.push_back({first, second});      
    }
 
    return res;
} 

// Efficient solution
vector<vector<int>> mergeEfficientSolution(vector<vector<int>>& intervals) {

    int row = intervals.size();
    int col = intervals[0].size();

    if(row == 1){
        return intervals;
    }

    vector<vector<int>> res;

    sort(intervals.begin(), intervals.end());

    int start = intervals[0][0];
    int end = intervals[0][1];

    for(int i = 1; i < row ; i++){

       if(intervals[i][0] <= end){
         end = max(end, intervals[i][1]);
       }
       else{
        res.push_back({start, end});
        start = intervals[i][0];
        end = intervals[i][1];
       }

    }
    res.push_back({start, end});

    return res;
}