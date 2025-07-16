#include <iostream>
#include <vector>
using namespace std;

//Approach :  O(logn) time complexity , O(logn) + o(n) space complexity
class Solution{
    private:
        void heapifyDown(vector<int> &nums, int ind, int n){
            int left = 2*ind + 1;
            int right = 2*ind + 2;

            int largest = ind;
            if(left < n && nums[left] > nums[largest]) largest = left;
            if(right < n && nums[right] > nums[largest]) largest = right;

            if(largest != ind){
                swap(nums[largest], nums[ind]);
                heapifyDown(nums, largest, n);
            }

            return;
        }

        void heapifyUp(vector<int> &nums, int ind, int n){
            int parent = (ind - 1)/2;

            if(ind > 0){
                if(nums[parent] < nums[ind]){
                    swap(nums[parent], nums[ind]);
                    heapifyUp(nums, parent, n);
                }
            }

            return;
        }
    public:
        vector<int> heapArr;
        // O(1)
        void initializeHeap(){
            heapArr.clear();
        }

        // O(logn)
        void insert(int key){
            heapArr.push_back(key);
            int ind = heapArr.size() - 1;
            heapifyUp(heapArr, ind, heapArr.size());
        }
        // O(logn)
        void changeKey(int index, int new_val){
            if(index < 0 || index >= heapArr.size()) return;
            
            if(heapArr[index] < new_val){
                heapArr[index] = new_val;
                heapifyUp(heapArr, index, heapArr.size());
            }
            else{
                heapArr[index] = new_val;
                heapifyDown(heapArr, index, heapArr.size());
            }            
        }

        // O(logn)
        void extractMax(){
            int n = heapArr.size();
            if(n == 0) return;

            swap(heapArr[0], heapArr[n - 1]);
            heapArr.pop_back();

            heapifyDown(heapArr, 0, heapArr.size());
        }
        // O(1)
        bool isEmpty(){
            return heapArr.size() == 0;
        }
        // O(1)
        int getMax(){
            return heapArr.size() > 0 ? heapArr[0] : -1;
        }
        // O(1)
        int heapSize(){
            return heapArr.size();
        }
};