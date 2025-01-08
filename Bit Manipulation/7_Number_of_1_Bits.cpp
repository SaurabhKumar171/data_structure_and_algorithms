class Solution
{
public:
    int hammingWeight(int n)
    {
        int cnt = 0;
        while (n != 1)
        {
            int rem = n % 2;
            if (rem == 1)
                cnt++;
            n = n / 2;
        }

        cnt++;

        return cnt;
    }
};