/*
The goal is to compute x raised to the power n efficiently even when n is negative.

The function uses recursive fast exponentiation (a.k.a. binary exponentiation) to reduce time complexity.

Trick:
Divide the power in half repeatedly:
If n is even: xⁿ = (x²)^(n/2)
If n is odd: xⁿ = x * (x²)^(n//2)
If n is odd: multiply an extra x 

Important Edge Case Handling:
n can be negative, so:
Convert n to a long long (N) to avoid overflow when negating INT_MIN.
Take reciprocal of x and use -n for negative powers.
*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        double half = myPow(x, N / 2);
        if (N % 2 == 0)
            return half * half;
        else
            return half * half * x;
    }
};