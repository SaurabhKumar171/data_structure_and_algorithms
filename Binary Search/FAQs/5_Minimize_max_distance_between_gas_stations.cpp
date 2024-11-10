#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Optimal Aproach ( Binary search )
class Solution {
private:
    /* Function to calculate the number of gas 
    stations required for given distance*/
    int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
        // Size of the array
        int n = arr.size(); 
        int cnt = 0;
        for (int i = 1; i < n; i++) {
            /* Calculate number of gas stations
            needed between two points*/
            int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
            
            // Adjust if exact distance fits perfectly
            if ((arr[i] - arr[i - 1]) == (dist * numberInBetween)) {
                numberInBetween--;
            }
            
            cnt += numberInBetween;
        }
        return cnt;
    }
    
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       
        int n = arr.size(); 
        long double low = 0;
        long double high = 0;

        /* Find the maximum distance between
        consecutive gas stations*/
        for (int i = 0; i < n - 1; i++) {
            high = max(high, (long double)(arr[i + 1] - arr[i]));
        }

        /* Apply Binary search to find the 
        minimum possible maximum distance*/
        long double diff = 1e-6;
        while (high - low > diff) {
            long double mid = (low + high) / 2.0;
            int cnt = numberOfGasStationsRequired(mid, arr);

            /* Adjust the search range based on 
            the number of gas stations required*/
            if (cnt > k) {
                low = mid;
            } else {
                high = mid;
            }
        }

        // Return the smallest maximum distance found
        return high;
    }
};

// Better Approach ( Priority queue )
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       
       int n = arr.size();
       vector<int> howMany(n - 1, 0);

        priority_queue<pair<long double, int>> pq; 


        for (int i = 0; i < n - 1; i++) {
            pq.push({(long double)(arr[i + 1] - arr[i]), i});
        }

       for(int i = 1; i <= k; i++){

        auto tp = pq.top(); 
        pq.pop(); 

        int secInd = tp.second; 

        howMany[secInd]++;

        long double inidiff = (long double)(arr[secInd + 1] - arr[secInd]);
        
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
           
        pq.push({newSecLen, secInd});

       }
        
        return pq.top().first; 

    }
};

// Brute force ( Linear search )
class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       
       int n = arr.size();
       vector<int> howMany(n - 1, 0);

       for(int i = 1; i <= k; i++){  

        double maxDist = -1;
        int maxDistId = -1;

        for(int i = 0; i < n - 1; i++){  
            double dist = arr[i+1] - arr[i];
            double sectionLength = dist/(howMany[i]+1);

            if(maxDist < sectionLength){
                maxDist = sectionLength;
                maxDistId = i;
            }
        }

        howMany[maxDistId]++;

       }

        double maxDist = -1;

       for(int i = 0; i < n-1; i++){  
        double dist = arr[i+1] - arr[i];
        double sectionLength = dist/(howMany[i]+1);
        maxDist = max(maxDist, sectionLength);
        // minDist = (long double)((arr[i] - arr[i-1])/howMany[i-1]);
       }

       return maxDist;
    }
};
