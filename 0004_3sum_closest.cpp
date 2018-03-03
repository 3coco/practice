// https://leetcode.com/problems/3sum-closest/description/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution4 {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        vector<int> v(nums.begin(), nums.end());
        int n = v.size();
        int ans = 0;
        int sum;
        
        if(nums.size() <= 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }

        sort(v.begin(), v.end());

        ans = v[0] + v[1] + v[2];
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                sum = v[i] + v[j] + v[k];
                if(sum == target) {
                    return sum;
                }
                
                (sum > target) ? k-- : j++;
                if(abs(sum - target) < abs(ans - target)) {
                    ans = sum;
                }
            } // end of while loop
        } // end of for loop
        return ans;
    }
};

int main() {
    Solution4 sol;
    int nums1[4] = {-1, 2, 1, -4};
    vector<int> vec1(nums1, nums1 + 4);
    int ans1 = 2;
    int ret1 = sol.threeSumClosest(vec1, 1);
    if(ret1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
