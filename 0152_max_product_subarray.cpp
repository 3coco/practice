// https://leetcode.com/problems/maximum-product-subarray/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution152 {
public:
    int maxProduct(vector<int> &nums) {
        int cur_max = nums[0];
        int tmp_min = nums[0];
        int tmp_max = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < 0) {
                swap(tmp_min, tmp_max);
            }
            tmp_max = max(nums[i], tmp_max * nums[i]);
            tmp_min = min(nums[i], tmp_min * nums[i]);
            cur_max = max(cur_max, tmp_max);
        }
        return cur_max;
    }
};

int main() {
    Solution152 sol;
    vector<int> nums1 {2, 3, -2, 4};
    if(sol.maxProduct(nums1) != 6) {
        cout << "Test #1 failed" << endl;
    }
    return 0;
}
