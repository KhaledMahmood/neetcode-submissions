/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int goodNodes(TreeNode* root) {
        return process(root, root->val);
    }

    int process(TreeNode* root, int max) {

        if(root == nullptr) {
            return 0;
        }

        return process(root->left, std::max(max, root->val)) + 
               process(root->right, std::max(max, root->val)) + 
               (root->val >= max ? 1 : 0);
    }
};
