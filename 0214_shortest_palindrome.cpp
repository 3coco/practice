// https://leetcode.com/problems/shortest-palindrome/description/

#include <iostream>
#include <string>

using namespace std;

class Solution214 {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        for(int i = 0; i < n; i++) {
            if(s.substr(0, n - i) == rev.substr(i)) {
                return rev.substr(0, i) + s;
            }
        }
        return "";
    }
};

int main() {
    Solution214 sol;
    if(sol.shortestPalindrome("aacecaaa") != "aaacecaaa") {
        cout << "Test #1 failed" << endl;
    }
    if(sol.shortestPalindrome("abcd") != "dcbabcd") {
        cout << "Test #2 failed" << endl;
    }
    return 0;
}
