// https://leetcode.com/problems/remove-k-digits/description/

#include <iostream>
#include <string>

using namespace std;

class Solution402 {
public:
    string removeKdigits(string num, int k) {
        if(num.length() == 0 || num.length() <= k) {
            return "0";
        }

        unsigned int len = num.length();
        char my_stack[len];
        unsigned int my_len = len - k;
        unsigned int top = 0;
        unsigned int idx = 0;

        my_stack[top++] = num[0];
        for(int i = 1; i < len; i++) {
            while(top > 0 && k > 0 && my_stack[top - 1] > num[i]) {
                top--;
                k--;
            }
            my_stack[top++] = num[i];
        }

        while(idx < top && my_stack[idx] == '0') {
            idx++;
        }

        return my_len > idx ? string(my_stack, idx, my_len -idx) : "0";
    }

};

int main() {
    Solution402 sol;
    if(sol.removeKdigits("1432219", 3) != "1219") {
        cout << "Test #1 failed" << endl;
    }
    if(sol.removeKdigits("10200", 1) != "200") {
        cout << "Test #2 failed" << endl;
    }
    if(sol.removeKdigits("10", 2) != "0") {
        cout << "Test #3 failed" << endl;
    }
    if(sol.removeKdigits("123", 2) != "1") {
        cout << "Test #4 failed" << endl;
    }
    return 0;
}
