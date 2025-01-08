#include <bits/stdc++.h>
using namespace std;

int unsetLSB(int N)
{
    return (N & (N - 1));
}

int main()
{
    // your code goes here
    cout << unsetLSB(13) << endl;
    return 0;
}
