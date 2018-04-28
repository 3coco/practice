// https://leetcode.com/problems/house-robber/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution198 {
public:
    int rob(vector<int> &nums) {
        if(nums.size() == 0 || nums.size() == 1) {
            return nums.size() == 0 ? 0 : nums[0];
        }
        unsigned int size = nums.size();
        int prevMax = nums[0];
        int currMax = max(nums[0], nums[1]);

        for(int i = 2; i < size; i++) {
            int temp = currMax;
            currMax = max(currMax, prevMax + nums[i]);
            prevMax = temp;
        }
        return currMax;
    }
};

int main() {
    Solution198 sol;
    vector<int> vec1 {1, 5, 3, 4, 10};
    if(sol.rob(vec1) != 15) {
        cout << "Test #1 failed"<< endl;
    }
    return 0;
}
