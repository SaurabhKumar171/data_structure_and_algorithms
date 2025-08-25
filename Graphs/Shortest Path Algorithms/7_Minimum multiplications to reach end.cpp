
#include <iostream>
#include <vector>
using namespace std;

// Time Complexity:O(100000 + k*n), where k is the number of nodes visited in the queue (worst case 100000) and n is the size of the input array arr.
// Space Complexity:O(100000) due to the distances vector and the queue which in the worst case can hold all 100000 nodes.
class Solution{
public:
    int minimumMultiplications(vector<int> &arr,
                               int start, int end) {
        
        if(start == end) return 0;
        
        queue<pair<int, int>> q;
        vector<int> distances(100000, 1e9);

        q.push({0, start});
        distances[start] = 0;
        int mod = 100000;
        while(!q.empty()){
            int node = q.front().second;
            int dist = q.front().first;
            q.pop();
            
            for(int it: arr){
                int newNode = (it*node) % mod;

                if(dist + 1 < distances[newNode]){
                    distances[newNode] = dist + 1;
                    if(newNode == end) return dist + 1;
                    q.push({dist + 1, newNode});
                }
            }
        }

        return -1;
    }
};
