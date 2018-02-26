// https://leetcode.com/problems/rotate-image/description/

#include <iostream>
#include <vector>

using namespace std;

class Solution48 {
public:
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

int main() {
    Solution48 sol;
    vector<vector<int> > matrix1 {{1, 2, 3},
                                  {4, 5, 6},
                                  {7, 8, 9}};
    vector<vector<int> > ans1 {{7, 4, 1},
                               {8, 5, 2},
                               {9, 6, 3}};
    sol.rotate(matrix1);
    if(matrix1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
