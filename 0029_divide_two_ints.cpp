#include <climits>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Solution29 {
    public:
        int divide(int dividend,int divisor) {
            if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
                return INT_MAX;
            }
            int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
            long long dvd = labs(dividend);
            long long dvs = labs(divisor);
            int res = 0;
            while(dvd >= dvs) {
                long long tmp = dvs;
                long long multi = 1;

                while(dvd >= (tmp << 1)) {
                    multi <<= 1;
                    tmp <<= 1;
                }
                dvd -= tmp;
                res += multi;
            }

            return sign == 1 ? res : -res;
        }
};

int main() {
    Solution29 sol;
    int ret = sol.divide(17, 5);
    int ans = 3;
    if(ret != ans) {
        cout << "Test#1 failed" << endl;
    }

    ret = sol.divide(-100, 13);
    ans = -7;
    if(ret != ans) {
        cout << "Test#2 failed" << endl;
    }

    ret = sol.divide(1, 2);
    ans = 0;
    if(ret != ans) {
        cout << "Test#3 failed" << endl;
    }

    return 0;
}
