#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    public:
        int maxScore(vector<int>& cardPoints, int k) {
            int n = cardPoints.size();
            int currSum = 0;
            for(int i = 0; i < k; i++){
                currSum += cardPoints[i];
            }
    
            int l = k - 1;
            int r = n - 1;
            int totalScore = currSum;
    
            while(l >= 0){
                currSum -= cardPoints[l];
                l--;
                currSum += cardPoints[r];
                r--;
                totalScore = max(totalScore, currSum);
            }
    
            return totalScore;     
        }
    };