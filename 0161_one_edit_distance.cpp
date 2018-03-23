// https://leetcode.com/problems/one-edit-distance/description/

#include <iostream>
#include <string>

using namespace std;

class Solution161 {
public:
    bool isOneEditDistance(string s, string t) {
        for(int i = 0; i < min(s.length(), t.length()); i++) {
            if(s[i] != t[i]) {
                if(s.length() == t.length()) {
                    return (s.substr(i + 1) == t.substr(i + 1));
                } else if (s.length() < t.length()){
                    return (s.substr(i) == t.substr(i + 1));
                } else {
                    return (s.substr(i + 1) == t.substr(i));
                }
            }
        }
        return abs((int)(s.length() - t.length())) == 1;
    }
};

int main() {
    Solution161 sol;
    if(!sol.isOneEditDistance("car", "cat")) {
        cout << "Test #1 failed." << endl;
    }
    if(sol.isOneEditDistance("cat", "dog")) {
        cout << "Test #2 failed." << endl;
    }
    return 0;
}
