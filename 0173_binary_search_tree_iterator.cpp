// https://leetcode.com/problems/binary-search-tree-iterator/description/

#include <iostream>
#include <stack>

using namespace std;

/* Definition for binary tree */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode *cur = root;
		while(cur != NULL) {
			s.push(cur);
			cur = cur -> left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !s.empty();        
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tn = s.top();
        s.pop();
		if(tn -> right != NULL) {
			TreeNode *cur = tn -> right;
			while(cur != NULL) {
				s.push(cur);
				cur = cur -> left;
			}
		}
		return tn -> val;
    }

private:
	stack<TreeNode*> s;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
