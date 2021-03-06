// https://leetcode.com/problems/minimum-size-subarray-sum/description/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution209{
public:
    // Solution 1: use binary search
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        int ans = INT_MAX;
        vector<int> sums(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        for(int i = 1; i <= n; i++) {
            // we need to find a j s.t. sums[j] - sums[i] + nums[i - 1] >= s
            // sums[j] - (sums[i] - nums[i - 1]) >= s
            // sums[j] >= s + sums[i - 1]
            int to_find = s + sums[i - 1];
            auto j = lower_bound(sums.begin(), sums.end(), to_find);
            if(j != sums.end()) {
                ans = min(ans, static_cast<int>(j - sums.begin() - i + 1));
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }

    // Solution 2: use two pointers
    int minSubArrayLen2(int s, vector<int> &nums) {
        int ans = INT_MAX;
        int sum = 0, j = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while(sum >= s) {
                ans = min(i - j + 1, ans);
                sum -= nums[j++];
            }
        }
        return ans != INT_MAX ? ans : 0;
    }
};

int main() {
    Solution209 sol;
    vector<int> vec1 {2, 3, 1, 2, 4, 3};
    if(sol.minSubArrayLen(7, vec1) != 2) {
        cout << "Test #1 failed" << endl;
    }

    if(sol.minSubArrayLen2(7, vec1) != 2) {
        cout << "Test #2 failed" << endl;
    }
    return 0;
}
