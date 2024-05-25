#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>

void reverseString(vector<char>& s) {

    int i = 0;
    int j = s.size()-1;

    while( i < j){
        char str = s[i];
        s[i] = s [j];
        s[j] = str;

        i++;
        j--;
    }
}