#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

// Better Approach
class Solution1 {
public:
    void sortZeroOneTwo(vector<int>& a) {
        
        int zerCnt = 0, oneCnt = 0, twoCnt = 0;
        int n = a.size();

        for(int i = 0; i < n; i++){
            if(a[i] == 0) zerCnt++;
            else if(a[i] == 1) oneCnt++;
            else twoCnt++;
        }

        int k = 0;
        while(zerCnt > 0){
            a[k++] = 0;
            zerCnt--;
        }
        while(oneCnt > 0){
            a[k++] = 1;
            oneCnt--;
        }
        while(twoCnt > 0){
            a[k++] = 2;
            twoCnt--;
        }
    }
};


// Optimal Approach
class Solution2 {
public:
    void sortZeroOneTwo(vector<int>& a) {
        
        int n = a.size();
        int l = 0, m = 0, h = n - 1;

        while(m <= h){
            if(a[m] == 0){
                swap(a[l], a[m]);
                l++, m++;
            }
            else if(a[m] == 2){
                swap(a[m], a[h]);
                h--;
            }
            else{
                m++;
            }
        }
    }
};