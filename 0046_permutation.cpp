// https://leetcode.com/problems/permutations/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution46 {
public:
	vector<vector<int> > permute(vector<int> &nums) {
		vector<vector<int> > results;
		helper(nums, 0, nums.size(), results);
		return results;
	}

private:
	void helper(vector<int> nums, int i, int j, vector<vector<int> > &results) {
		if(i == j - 1) {
			results.push_back(nums);
			return;
		}
		for(int k = i; k < j; k++) {
			swap(nums[i], nums[k]);
			helper(nums, i + 1, j, results);
		}
	}
};

int main() {
	Solution46 sol;
	vector<vector<int> > ans1 {{1, 2, 3},
                               {1, 3, 2},
                               {2, 1, 3},
                               {2, 3, 1},
                               {3, 1, 2},
                               {3, 2, 1}};
	vector<int> nums1{1, 2, 3};
	vector<vector<int> > ret1 = sol.permute(nums1);
	if(ret1 != ans1) {
		cout << "Test#1 failed" << endl;
	}

	return 0;
}
