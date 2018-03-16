 // https://leetcode.com/problems/find-peak-element/description/
 
 #include <vector>
 #include <iostream>
 
 using namespace std;
 
 class Solution162 {
 public:
     int findPeakElement(vector<int> &nums) {
         int l = 0;
         int h = nums.size() - 1;
 
         while(l < h) {
             int mid = l + (h - l) / 2;
             if(nums[mid] > nums[mid + 1]) {
                 h = mid;
             } else {
                 l = mid + 1;
             }
         }
 
         return l;
     }
 };
 
 int main() {
     Solution162 sol;
     vector<int> nums{1, 2, 3, 1};
     if(sol.findPeakElement(nums) != 2) {
         cout << "Test #1 failed." << endl;
     }
     return 0;
 }
