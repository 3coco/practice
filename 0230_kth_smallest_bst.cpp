// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution230 {
private:
    int countNodes(TreeNode *node) {
        if(node == NULL) {
            return 0;
        }
   
        return 1 + countNodes(node -> left) + countNodes(node -> right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count = countNodes(root -> left);

        if(count >= k) {
            return kthSmallest(root -> left, k);
        } else if (count < k - 1) {
            return kthSmallest(root -> right, k - count - 1); 
        }
        return root -> val;
    }
};

int main() {
    // TODO: test cases
    return 0;
}
