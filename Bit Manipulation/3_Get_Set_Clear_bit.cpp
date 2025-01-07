#include <iostream>
using namespace std;
class Solution
{
private:
    int getBit(int num, int i)
    {
        return ((num & (1 << (i - 1))) >> (i - 1));
    }

    int setBit(int num, int i)
    {
        return (num | (1 << (i - 1)));
    }

    int clearBit(int num, int i)
    {
        return (num & (~(1 << (i - 1))));
    }

public:
    void bitManipulation(int num, int i)
    {
        // your code here
        cout << getBit(num, i) << " ";
        cout << setBit(num, i) << " ";
        cout << clearBit(num, i) << " ";
    }
};