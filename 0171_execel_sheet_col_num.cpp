// https://leetcode.com/problems/excel-sheet-column-number/description/

#include <iostream>

using namespace std;

class Solution171 {
public:
    int titleToNumber(string s) {
        int result = 0;
        for(int i = 0; i < s.size(); i++) {
            result = (result * 26) + (s[i] - 'A' + 1);
        }
        return result;
    }
};

int main() {
    Solution171 sol;
    if(sol.titleToNumber("AB") != 28) {
        cout << "Test #1 failed." << endl;
    }

    return 0;
}
