#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Optimal Approach  O(n * log(m) + n * log(max-min))
class Solution{
private:
    int upperBound(vector<int> arr, int m, int x){
        
        int low = 0;
        int high = m - 1;
        int ans = 0;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] > x){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return low;
    }

    int countSmallerEqual(vector<vector<int>>&matrix, int n, int m, int x){

        int cnt = 0;

        for(int i = 0; i < n; i++){
            cnt += upperBound(matrix[i], m, x);
        }

        return cnt;
    }

public:
    int findMedian(vector<vector<int>>&matrix) {
        
        int n = matrix.size();
        int m = matrix[0].size(); 

        int low = INT_MAX;
        int high = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m-1]);
        }

        int req = (n*m)/2;

        while(low <= high){
            int mid = (low+high)/2;

            int smallEquals = countSmallerEqual(matrix, n, m, mid);

            if(smallEquals <= req) low = mid+1;
            else high = mid - 1;
        }

        return low;
    }
};


// Brute force Approach O(r*c)
class Solution{
public:
    int findMedian(vector<vector<int>>&matrix) {
        
        vector<int> lst;
        int n = matrix.size();
        int m = matrix[0].size(); 
        
        /* Traverse the matrix and 
        copy the elements to list*/
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                lst.push_back(matrix[i][j]);
            }
        }

        sort(lst.begin(), lst.end());

        return lst[(n*m)/2];
    }
};
