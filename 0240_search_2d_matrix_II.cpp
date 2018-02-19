// https://leetcode.com/problems/search-a-2d-matrix-ii/description/

#include <iostream>
#include <vector>

using namespace std;
class Solution240 {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.size() == 0) {
            return false;
        }
        return binarySearchMatrix(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1, target);        
    }

private:
    bool binarySearchMatrix(vector<vector<int> > &matrix, int top,
            int left, int down, int right, int target) {
        if(top > down || left > right ||
                target < matrix[top][left] || target > matrix[down][right]) {
            return false;
        }
        int mid = left + (right - left) / 2;
        int row = top;
        while(row <= down && matrix[row][mid] <= target) {
            if(matrix[row][mid] == target) {
                return true;
            }
            row++;
        }
		
        /*  bug test failed: matrix = {1, 3, 5}, target = 1
        int row = 0;
        for(int i = 0; i < matrix.size(); i++) {
            if(matrix[i][mid] == target) {
                return true;
            } else if(matrix[i][mid] < target) {
                row = i;
            } else {
                break;
            }
        }
 
        return (binarySearchMatrix(matrix, row + 1, left, down, mid - 1, target) ||
                 binarySearchMatrix(matrix, top, mid + 1, row, right, target));
        */

        return (binarySearchMatrix(matrix, row, left, down, mid - 1, target) || 
                binarySearchMatrix(matrix, top, mid + 1, row - 1, right, target));
    }
};

int main() {
    Solution240 sol;
    vector<vector<int> > m1;
    int r1[5] = {1, 4, 7, 11, 15};
    m1.push_back(vector<int>(r1, r1 + 5));
    int r2[5] = {2, 5, 8, 12, 19};
    m1.push_back(vector<int>(r2, r2 + 5));
    int r3[5] = {3, 6, 9, 16, 22};
    m1.push_back(vector<int>(r3, r3 + 5));
    int r4[5] = {10, 13, 14, 17, 24};
    m1.push_back(vector<int>(r4, r4 + 5));
    int r5[5] = {18, 21, 23, 26, 30};
    m1.push_back(vector<int>(r5, r5+ 5));
    bool ret1 = sol.searchMatrix(m1, 5);
    bool ans1 = true;
    if(ret1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    bool ret2 = sol.searchMatrix(m1, 15);
    bool ans2 = true;
    if(ret2 != ans2) {
        cout << "Test#2 failed" << endl;
    }

    vector<vector<int> > m2;
    int m2r1[1] = {1};
    m2.push_back(vector<int>(m2r1, m2r1 + 1));
    int m2r2[1] = {3};
    m2.push_back(vector<int>(m2r2, m2r2 + 1));
    bool ret3 = sol.searchMatrix(m2, 2);
    bool ans3 = false;
    if(ret3 != ans3) {
        cout << "Test#3 failed" << endl;
    }

    bool ret4 = sol.searchMatrix(m2, 3);
    bool ans4 = true;
    if(ret4 != ans4) {
        cout << "Test#4 failed" << endl;
    }

    vector<vector<int> > m3;
    int m3r1[3] = {1, 3, 5};
    m3.push_back(vector<int>(m3r1, m3r1 + 3));
    bool ret5 = sol.searchMatrix(m3, 1);
    bool ans5 = true;
    if(ret5 != ans5) {
        cout << "Test#5 failed" << endl;
    }

    bool ret6 = sol.searchMatrix(m3, 5);
    bool ans6 = true;
    if(ret6 != ans6) {
        cout << "Test#6 failed" << endl; 
    }

	bool ret7 = sol.searchMatrix(m3, 2);
	bool ans7 = false;
	if(ret7 != ans7) {
		cout << "Test#7 failed" << endl;
	}
}

