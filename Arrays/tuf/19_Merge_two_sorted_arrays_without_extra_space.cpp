#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Brute force
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> temp;

        int i = 0;
        int j = 0;

        while(i< m && j < n){

            if(nums1[i] < nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                temp.push_back(nums2[j]);
                j++;
            }
            else{
                temp.push_back(nums1[i]);
                temp.push_back(nums2[j]);
                i++;
                j++;
            }
        }

        while(i < m){
            temp.push_back(nums1[i]);
            i++;
        }

        while(j < n){
            temp.push_back(nums2[j]);
            j++;
        }

        for(int i = 0; i < m+n; i++){
            nums1[i] = temp[i];
        }
    }
};

// Optimal approach (without extra space )
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = 0;

        while(i >= 0 && j < n){

            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                
                int k = i;
                while(k > 0 && nums1[k] < nums1[k-1]){
                    swap(nums1[k], nums1[k-1]);
                    k--;
                }

                int p = j;
                while(p < n-1 && nums2[p] > nums2[p+1]){
                    swap(nums2[p], nums2[p+1]);
                    p++;
                }
            }
            else{
                i--;
                j++;
            }
        }

        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[i - m];
        }
    }
};


// Optimal approach - I
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int i = m-1;
        int j = 0;

        while(i >= 0 && j < n){

            if(nums1[i] > nums2[j]){
                swap(nums1[i], nums2[j]);
                i--;
                j++;
            }
            else{
                break;
            }
        }

        sort(nums1.begin(), nums1.begin() + m);

        sort(nums2.begin(), nums2.end());

        for(int i = m; i < m+n; i++){
            nums1[i] = nums2[i-m];
        }

    }
};
   
// Optimal Approach - II
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i = m; i< m+n; i++){
            nums1[i] = nums2[i-m];
        }

        double g = (double(m)+n)/2;
        int gap = int(ceil(g));

        while(gap >= 1){
            
            int i = 0;
            int j = i + gap;

            while(j < m+n){
                
                if(nums1[i] > nums1[j]){
                    swap(nums1[i], nums1[j]);
                }
                i++,j++;
            }

            if(gap == 1) break;

            gap = int(ceil((double)(gap)/2));
        }
    }
};