// https://leetcode.com/problems/sort-colors/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution75 {
public:
    void sortColors(vector<int> &nums) {
        int f1 = 0; // first one
        int f2 = nums.size() - 1; // first two
        for(int i = 0; i <= f2;) {
            if(nums[i] == 0) {
                swap(nums[i++], nums[f1++]);
            } else if(nums[i] == 2) {
                swap(nums[i], nums[f2--]);
            } else { 
                i++; // nums[i] == 1
            }
        }
    }
};

int main() {
    Solution75 sol;
    int nums1[3] = {2, 1, 0};
    vector<int> vec1(nums1, nums1 + sizeof(nums1) / sizeof(nums1[0]));
    int n1[3] = {0, 1, 2};
    vector<int> ans1(n1, n1 + sizeof(n1) / sizeof(n1[0]));
    sol.sortColors(vec1);
    if(vec1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    int nums2[6] = {2, 2, 1, 2, 1, 1};
    vector<int> vec2(nums2, nums2 + sizeof(nums2) / sizeof(nums2[0]));
    int n2[6] = {1, 1, 1, 2, 2, 2};
    vector<int> ans2(n2, n2 + sizeof(n2) / sizeof(n2[0]));
    sol.sortColors(vec2);
    if(vec2 != ans2) {
        cout << "Test#2 failed" << endl;
    }

    int nums3[15] = {0, 2, 1, 2, 0, 1, 0, 1, 1, 2, 0, 0, 1, 0, 1};
    vector<int> vec3(nums3, nums3 + sizeof(nums3) / sizeof(nums3[0]));
    int n3[15] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2};
    vector<int> ans3(n3, n3 + sizeof(n3) / sizeof(n3[0]));
    sol.sortColors(vec3);
    if(vec3 != ans3) {
        cout << "Test#3 failed" << endl;
    }


    int nums4[15] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 2, 2, 2};
    vector<int> vec4(nums4, nums4 + sizeof(nums4) / sizeof(nums4[0]));
    sol.sortColors(vec4);
    if(vec4 != ans3) {
         cout << "Test#3 failed" << endl;
    }

    return 0;
}
