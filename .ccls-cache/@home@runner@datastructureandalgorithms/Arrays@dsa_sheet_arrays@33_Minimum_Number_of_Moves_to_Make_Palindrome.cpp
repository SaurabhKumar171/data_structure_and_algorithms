#include <iostream>
#include <vector>
using namespace std;

int minMovesToMakePalindrome(string s) {

    int n = s.size();
    int lt = 0;
    int rt = n-1;
    int count = 0;

    while(lt < rt){

        int l = lt;
        int r = rt;

        while(s[l] != s[r]){ r--; }

        if(l == r){
            swap(s[r],s[r+1]);
            count++;
            continue;
        }
        else{
            while(r < rt){
                swap(s[r],s[r+1]);
                r++;
                count++;
            }  
        }      

        lt++;
        rt--;
    }

    return count;
}