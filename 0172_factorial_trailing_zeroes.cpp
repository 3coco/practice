// https://leetcode.com/problems/factorial-trailing-zeroes/description/

class Solution172 {
public:
    int trailingZeros(int n) {
        int result = 0;
        for(long long i = 5; n / i > 0; i *= 5) {
            result += (n / i);
        }

        return result;
    }
}
