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