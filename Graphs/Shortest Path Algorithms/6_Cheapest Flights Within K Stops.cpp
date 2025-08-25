
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
using namespace std;

class Solution{
public:
    int CheapestFlight(int n, vector<vector<int>> &flights,
                       int src, int dst, int k) {
        // source -> {destination, price}
        vector<vector<pair<int, int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        // {stops, prices, nodes(flights)}
        queue<vector<int>> q;
        vector<int> prices(n, 1e9);
        prices[src] = 0;
        q.push({0, 0, src});

        while(!q.empty()){

            int size = q.size();

            for(int i = 0; i < size; i++){
                auto it = q.front();
                q.pop();

                int stops = it[0];
                int dist = it[1];
                int node = it[2];

                if(stops > k ) continue;

                for(auto neigh: adj[node]){
                    int newPrice = dist + neigh.second;
                    int newDist = neigh.first;

                    if(prices[newDist] > newPrice){
                        prices[newDist] = newPrice;
                        q.push({stops + 1, newPrice, newDist});
                    }
                }
            }

        }

        return prices[dst] == 1e9 ? -1 : prices[dst];        
    }
};
