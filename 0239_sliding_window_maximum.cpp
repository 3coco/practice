// https://leetcode.com/problems/sliding-window-maximum/description/

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i-k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};

int main() {
	Solution239 sol;
	vector<int> nums {1, 3, -1, -3, 5, 3, 6, 7};
	vector<int> ret = sol.maxSlidingWindow(nums, 3);
	vector<int> ans {3, 3, 5, 5, 6, 7};
	if(ret != ans) {
        cout << "Test #1 failed." << endl;  
    }
    return 0;
}
