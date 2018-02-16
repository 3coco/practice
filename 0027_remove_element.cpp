// https://leetcode.com/problems/remove-element/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution27 {
public:
    int removeElement(vector<int> &nums, int val) {
       int result = 0;
       for(int i = 0; i < nums.size(); i++) {
           if(nums[i] != val) {
               nums[result++] = nums[i];
           }
       }

       return result;
    }
};

int main() {
    Solution27 sol;
    int nums[4] = {3, 2, 2, 3};
    vector<int> vec1(nums, nums + sizeof(nums) / sizeof(nums[0]));
    int ret = sol.removeElement(vec1, 3);
    int ans = 2;
    if(ret != ans) {
        cout << "Test#1 failed" << endl;
    }
}
