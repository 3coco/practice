// https://leetcode.com/problems/largest-number/description/

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution179 {
public:
    string largestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
                    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
                });
        string result;
        for(int i = 0; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }
        return result[0] == '0' ? "0" : result;
    }
};

int main() {
    Solution179 sol;
    vector<int> vec1 {3, 30, 34, 5, 9};
    if(sol.largestNumber(vec1) != "9534330") {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
