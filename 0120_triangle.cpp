// https://leetcode.com/problems/triangle/description/

#include <vector>
#include <iostream>

using namespace std;

class Solution120 {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        if(triangle.size() == 0) { 
            return 0; 
        }
        vector<int> min_vec(triangle[triangle.size() - 1]);
        for(int i = triangle.size() - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                min_vec[j] = triangle[i][j] + min(min_vec[j], min_vec[j + 1]);
            }
        }
        return min_vec[0];
    }
};

int main() {
    Solution120 sol;
    int row0[1] = {2};
    int row1[2] = {3, 4};
    int row2[3] = {6, 5, 7};
    int row3[4] = {4, 1, 8, 3};

    vector<vector<int> > tri1;
    tri1.push_back(vector<int>(row0, row0 + sizeof(row0) / sizeof(row0[0])));
    tri1.push_back(vector<int>(row1, row1 + sizeof(row1) / sizeof(row1[0])));
    tri1.push_back(vector<int>(row2, row2 + sizeof(row2) / sizeof(row2[0])));
    tri1.push_back(vector<int>(row3, row3 + sizeof(row3) / sizeof(row3[0])));
    int ret = sol.minimumTotal(tri1);
    int ans = 11;
    if(ret != ans) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
