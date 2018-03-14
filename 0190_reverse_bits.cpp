// https://leetcode.com/problems/reverse-bits/description/

#include <stdint.h>
#include <iostream>
using namespace std;

class Solution190 {
public:
    uint32_t reverseBit(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main() {
    Solution190 sol;
    if(sol.reverseBit(43261596) != 964176192) {
        cout << "Test #1 failed" << endl;
    }
    return 0;
}
