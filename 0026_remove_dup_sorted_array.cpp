#include <iostream>
#include <vector>

using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int> &nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int result = 1;
        int prev = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != prev) {
                prev = nums[i];
                nums[result++] = nums[i]; 
            }
        }
        return result;
    }
};

int main() {
    Solution26 sol;
    int nums[7] = {1, 1, 2, 2, 3, 3, 3};
    vector<int> v1(nums, nums + sizeof(nums) / sizeof(nums[0]));
    int ret = sol.removeDuplicates(v1);
    int exp = 3;
    if(ret != exp) {
        cout << "Test #1 failed" << endl;
    }

    return 0;
}
