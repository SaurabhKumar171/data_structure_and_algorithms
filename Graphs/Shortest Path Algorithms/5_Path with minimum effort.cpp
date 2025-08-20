
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

// Time Complexity:O(m*n*log(m*n)) due to the priority queue operations, where m is the number of columns and n is the number of rows in the heights matrix.
// Space Complexity:O(m*n) primarily due to the distances matrix and the priority queue, both of which can store up to m*n elements in the worst case.
class Solution {
   public:
    int MinimumEffort(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;
        vector<vector<int>> distances(n, vector<int>(m, 1e9));

        distances[0][0] = 0;
        minHeap.push({0, {0, 0}});

        vector<int> delRow = {-1, 0 , 1, 0};
        vector<int> delCol = {0, 1, 0, -1};

        while(!minHeap.empty()){
            auto it = minHeap.top();
            minHeap.pop();

            int dist = it.first;
            int row = it.second.first;
            int col = it.second.second;
            // cout << "row -> " << row << " col -> " << col << endl;


            if(row == n - 1 && col == m - 1) return dist;

            for(int i = 0; i < 4; i++){
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newEffort = max(dist, abs(heights[newRow][newCol] - heights[row][col]));

                    if(newEffort < distances[newRow][newCol]){
                        distances[newRow][newCol] = newEffort;
                        minHeap.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }

        return -1;
    }
};
