// https://leetcode.com/problems/permutations-ii/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution47 {
public:
	vector<vector<int> > permuteUnique(vector<int> &nums) {
		sort(nums.begin(), nums.end());
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
			if(i != k && nums[i] == nums[k]) {
				continue;
			}
			swap(nums[i], nums[k]);
			helper(nums, i + 1, j, results);
		}
	}
};

int main() {
	Solution47 sol;
	vector<vector<int> > ans1{{1, 1, 2},
								{1, 2, 1},
								{2, 1, 1}};
	vector<int> nums1{1, 1, 2};
	vector<vector<int> > ret1 = sol.permuteUnique(nums1);
	if(ret1 != ans1) {
		cout << "Test#1 failed" << endl;
	}
	
	return 0;
}
