// https://leetcode.com/problems/compare-version-numbers/description/

#include <string>
#include <iostream>

using namespace std;

class Solution165 {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0, s1 = version1.size(), s2 = version2.size();

        while(i < s1 || j < s2) {
            int num1 = 0, num2 = 0;
            while(i < s1 && version1[i] != '.') {
                num1 = 10 * num1 + (version1[i] - '0');
                i++;
            }
            while(j < s2 && version2[j] != '.') {
                num2 = 10 * num2 + (version2[j] - '0');
                j++;
            }
            if(num1 > num2) {
                return 1;
            } else if(num1 < num2) {
                return -1;
            }
            i++;
            j++;
        }

        return 0;
    }
};

int main() {
    Solution165 sol;
    if(sol.compareVersion("1.1", "1.2") != -1) {
        cout << "Test #1 failed" << endl;
    }
    if(sol.compareVersion("1.0", "1") != 0) {
         cout << "Test #2 failed" << endl;
    }
    return 0;
}
