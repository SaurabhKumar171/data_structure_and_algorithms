// Brute force (T.C - { O(n)}, S.C - O(1))
class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        // Determine the sign of the result
        bool isPositive = (dividend < 0) == (divisor < 0);

        // Convert to long to handle overflow and take absolute values
        long n = labs(dividend);
        long d = labs(divisor);

        // Variables to store the result and sum
        long ans = 0, sum = 0;

        // Perform division using subtraction
        while (sum + d <= n)
        {
            ans++;
            sum += d;
        }

        // Return the quotient with the proper sign
        return isPositive ? ans : -ans;
    }
};

// Optimal solution (T.C - { O(logn)*O(logn)}, S.C - O(1))
class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        if (dividend == divisor)
            return 1;

        bool isPositive = true;

        if (dividend < 0 && divisor > 0)
            isPositive = false;
        if (dividend > 0 && divisor < 0)
            isPositive = false;

        long numerator = labs(dividend);
        long denominator = labs(divisor);

        long ans = 0;

        while (numerator >= denominator)
        {

            long cnt = 0;
            while (numerator > (denominator << (cnt + 1)))
            {
                cnt++;
            }

            ans += (pow(2, cnt));
            numerator -= (denominator << cnt);
        }

        if (!isPositive)
            ans *= -1;

        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;

        return ans;
    }
};