// https://leetcode.com/problems/binary-tree-right-side-view/description/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution199 {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> results;
        dfs(root, 0, results);
        return results;
    }

private:
    void dfs(TreeNode *node, int level, vector<int> &results) {
        if(node == NULL) {
            return;
        }
        if(level >= results.size()) {
            results.push_back(node -> val);
        }
        dfs(node -> right, level + 1, results);
        dfs(node -> left, level + 1, results);
    }
};

int main() {
    /*     1
     *   /   \
     *  2     3
     *   \     \
     *    5     4
     */
    Solution199 sol;
    TreeNode node1(1), node2(2), node3(3), node4(4), node5(5);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node5;
    node3.right = &node4;
    vector<int> ret1 = sol.rightSideView(&node1);
    vector<int> ans1;
    ans1.push_back(1);
    ans1.push_back(3);
    ans1.push_back(4);

    if(ret1 != ans1) {
        cout << "Test#1 failed" << endl;
    }

    return 0;
}
