// https://leetcode.com/problems/rotate-array/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution189 {
public:
    void rotate(vector<int> &nums, int k) {
        k = k % nums.size();
        int count = 0;

        for(int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % nums.size();
                int tmp = nums[next];
                nums[next] = prev;
                prev = tmp;
                current = next;
                count++;
            } while(start != current);
        }
    }
};

int main() {
    Solution189 sol;
    vector<int> vec1 {1, 2, 3, 4, 5, 6, 7};
    vector<int> ans1 {5, 6, 7, 1, 2, 3, 4};
    sol.rotate(vec1, 3);

    if(vec1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
