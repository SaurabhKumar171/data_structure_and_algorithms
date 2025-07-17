#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(nlogk) time complexity , O(k) space complexity
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;
  KthLargest(int k, vector<int>& nums) {
    this->k = k;
    for(int num: nums){
        add(num);
    }
  }

  int add(int val) {
    if(minHeap.size() >= k){
        if(val > minHeap.top()){
            minHeap.pop();
            minHeap.push(val); 
        }
    }
    else{
        minHeap.push(val);
    }
    
    return minHeap.top();
  }
};