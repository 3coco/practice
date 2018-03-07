// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution153 {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int h = nums.size() - 1;

        while(nums[l] > nums[h] && l < h) {
            int mid = l + (h - l) / 2;
            if(nums[mid] > nums[h]) {
                l = mid + 1;
            } else {
                h = mid;
            }
        }
        return nums[l];
    }
};

int main() {
    Solution153 sol;
    int nums1[1] = {1};
    vector<int> vec1(nums1, nums1 + 1);
    int ret1 = sol.findMin(vec1);
    int ans1 = 1;
    if(ret1 != ans1) {
        cout << "Test#1 failed" <<endl;
    }

    int nums2[2] = {1, 2};
    vector<int> vec2(nums2, nums2 + 2);
    int ret2 = sol.findMin(vec2);
    int ans2 = 1;
    if(ret2 != ans2) {
        cout << "Test#2 failed" << endl;
    }
    
    int nums3[2] = {2, 1};
    vector<int> vec3(nums3, nums3 + 2);
    int ret3 = sol.findMin(vec3);
    int ans3 = 1;
    if(ret3 != ans3) {
        cout << "Test#3 failed" << endl;
    }

    int nums4[7] = {4, 5, 6, 7, 0, 1, 2};
    vector<int> vec4(nums4, nums4 + 7);
    int ret4 = sol.findMin(vec4);
    int ans4 = 0;
    if(ret4 != ans4) {
        cout << "Test#4 failed" << endl;
    }
}
