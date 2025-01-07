// Online C++ compiler to run C++ program online
#include <iostream>

int toggleBit(int N, int i)
{
    return (N ^ (1 << i));
}
int main()
{
    // Write C++ code here
    std::cout << toggleBit(13, 2);

    return 0;
}