class Solution {
    public:
      double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
          // code here
          vector<pair<int, int>> store;
          double currWt = 0, totalVal = 0, n = val.size();
          for(int i = 0; i < n; i++){
              store.push_back({val[i], wt[i]});
          }
          
          sort(store.begin(), store.end(), [](const pair<int, int>& a, const pair<int, int>& b){
           double r1 = (double) a.first / (double) a.second;
           double r2 = (double) b.first / (double) b.second;
           return r1 > r2;
          });
          
          
          for(int i = 0; i < n; i++){
              if(capacity - store[i].second >= 0){
                  totalVal += store[i].first;
                  currWt += store[i].second;
                  capacity -= store[i].second;
              }
              else{
                  double x = (double)store[i].first/store[i].second;
                  currWt = store[i].second + (capacity - store[i].second);
                  totalVal += (x*currWt);
                  break;
              }
          }
          
          return (double)totalVal;
      }
  };