class Solution
{
public:
    int setKthBit(int N, int K)
    {
        // Write Your Code here
        return (N | (1 << K));
    }
};