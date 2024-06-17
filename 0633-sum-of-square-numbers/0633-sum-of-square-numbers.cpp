class Solution {
public:
    bool judgeSquareSum(int c) {

        for (long long a = 0; a*a <= c; a++)
        {
            long long bSquare = c - a*a;
            long long b = static_cast<long long> (sqrt(bSquare));
            if (b*b == bSquare) {
                return true;
            }
        }
        return false;
    }
};