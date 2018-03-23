// https://leetcode.com/problems/edit-distance/description/

#include <iostream>
#include <string>

using namespace std;

class Solution71 {
public:
    int minDistance(string word1, string word2) {
        int matrix[word1.length() + 1][word2.length() + 1];   
        for(int i = 0; i <= word2.length(); i++) {
            matrix[0][i] = i;
        }
        for(int i = 0; i <= word1.length(); i++) {
            matrix[i][0] = i;
        }

        for(int i = 1; i <= word1.length(); i++) {
            for(int j = 1; j <= word2.length(); j++) {
                int insert = matrix[i][j - 1] + 1;
                int del = matrix[i - 1][j] + 1;
                int replace = matrix[i - 1][j - 1] + (word1[i - 1] == word2[j - 1] ? 0 : 1);
                matrix[i][j] = min(min(insert, del), replace);
            }
        }
        return matrix[word1.length()][word2.length()];
    }
};

int main() {
    Solution71 sol;
    if(sol.minDistance("a", "b") != 1) {
        cout << "Test #1 failed." << endl;
    }
    return 0;
}
