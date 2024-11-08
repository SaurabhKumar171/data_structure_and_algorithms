#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> intersect(vector<int> nums1, vector<int> nums2) {

    vector<int> res;

    for(int i =0 ;i < nums1.size(); i++){
        for(int j =0 ;j < nums2.size(); j++){
            if(nums1[i] == nums2[j]){
                res.push_back(nums1[i]);
                nums2[j] = INT_MIN;
                break;
            }
        }
    }

    return res;
}