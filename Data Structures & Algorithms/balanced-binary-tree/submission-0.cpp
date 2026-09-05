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
    bool isBalanced(TreeNode* root) {

        if(nullptr == root) return true;

        return calcMaxHeight(root) == -1 ? false : true;
    }

    int calcMaxHeight(TreeNode* root) {
        
        if(root == nullptr) return 0;

        if(root->left == nullptr && root->right == nullptr) return 1;
        
        int maxR = calcMaxHeight(root->right);

        if(maxR == -1) return -1;

        int maxL = calcMaxHeight(root->left);

        if(maxL == -1) return -1;

        if(abs(maxR-maxL) > 1) return -1;

        return max(maxL, maxR) + 1;
    }
};
