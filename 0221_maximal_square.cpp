// https://leetcode.com/problems/maximal-square/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution221 {
public:
    int maximalSquare(vector<vector<char> > &matrix) {
        if(matrix.size() == 0) {
            return 0;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        vector<int> dp(cols + 1, 0);
        int max_len = 0, prev = 0;

        for(int i = 1; i <= rows; i++) {
            prev = 0;
            for(int j = 1; j <= cols; j++) {
                int temp = dp[j];
                if(matrix[i - 1][j - 1] == '1') {
                    dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
                    max_len = max(max_len, dp[j]);
                } else {
                    dp[j] = 0;
                }
                prev = temp;
            }
        }
        return max_len * max_len;
    }
};

int main() {
    Solution221 sol;
    vector<vector<char> > matrix1 {
        {'0', '1', '1', '1', '0'},
        {'1', '1', '1', '1', '0'},
        {'0', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '1'},
        {'0', '0', '1', '1', '1'}};
    int ans1 = 9;
    int ret1 = sol.maximalSquare(matrix1);

    if(ret1 != ans1) {
        cout << "Test#1 failed" << endl;
    }
    return 0;
}
