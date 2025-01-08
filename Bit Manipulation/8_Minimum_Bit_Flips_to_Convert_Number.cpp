// Optimal Soln (T.C - { O(1) + O(32)}, S.C - O(1))
class Solution
{
public:
    int minBitsFlip(int start, int goal)
    {
        // XOR to find diff. bits
        int diffBits = start ^ goal;

        int cnt = 0;
        // Count the number of 1s in diffBits (differing bits)
        while (diffBits != 1)
        {
            cnt += diffBits & 1; // increment if last bit is 1
            diffBits >>= 1;      // shift to process the next bit
        }

        if (diffBits == 1)
            cnt++;

        return cnt;
    }
};