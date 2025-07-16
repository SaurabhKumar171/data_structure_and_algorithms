#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(logn) time complexity , O(logn) + o(n) space complexity
class Solution{
    private:
        void heapifyDown(vector<int> &nums, int ind, int n){
            int left = 2*ind + 1;
            int right = 2*ind + 2;

            int smallest = ind;
            if(left < n && nums[left] < nums[smallest]) smallest = left;
            if(right < n && nums[right] < nums[smallest]) smallest = right;

            if(smallest != ind){
                swap(nums[smallest], nums[ind]);
                heapifyDown(nums, smallest, n);
            }

            return;
        }

        void heapifyUp(vector<int> &nums, int ind, int n){
            int parent = (ind - 1)/2;

            if(ind > 0){
                if(nums[parent] > nums[ind]){
                    swap(nums[parent], nums[ind]);
                    heapifyUp(nums, parent, n);
                }
            }

            return;
        }
    public:
        vector<int> heapArr;

        void initializeHeap(){
            heapArr.clear();
        }

        void insert(int key){
            heapArr.push_back(key);
            int ind = heapArr.size() - 1;
            heapifyUp(heapArr, ind, heapArr.size());
        }

        void changeKey(int index, int new_val){
            if(heapArr[index] > new_val){
                heapArr[index] = new_val;
                heapifyUp(heapArr, index, heapArr.size());
            }
            else{
                heapArr[index] = new_val;
                heapifyDown(heapArr, index, heapArr.size());
            }
        }

        void extractMin(){
            int n = heapArr.size();
            if(n == 0) return;

            // Swap root with last element and remove the last
            swap(heapArr[0], heapArr[n - 1]);
            heapArr.pop_back();

            // Restore heap property
            heapifyDown(heapArr, 0, heapArr.size());
        }

        bool isEmpty(){
            return heapArr.size() == 0;
        }

        int getMin(){
            return heapArr.size() > 0 ? heapArr[0] : -1;
        }

        int heapSize(){
            return heapArr.size();
        }
};