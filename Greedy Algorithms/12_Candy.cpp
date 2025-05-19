// Brute force approach
class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size();
            vector<int> leftCandies(n ,1);
            vector<int> rightCandies(n ,1);
    
            for(int i = 1; i < n; i++){
                if(ratings[i] > ratings[i - 1]){
                    leftCandies[i] = leftCandies[i - 1] + 1;
                }
            }
    
            for(int i = n - 2; i >= 0; i--){
                if(ratings[i] > ratings[i + 1]){
                    rightCandies[i] = rightCandies[i + 1] + 1;
                }
            }
    
            int candiesSum = 0;
            for(int i = 0; i < n; i++){
                candiesSum += max(leftCandies[i], rightCandies[i]);
            }
    
            return candiesSum;
        }
    };

    
// Optimal approach