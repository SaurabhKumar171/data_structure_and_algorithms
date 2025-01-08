class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(int n)
    {
        // code here
        return !(n & (n - 1));
    }
};