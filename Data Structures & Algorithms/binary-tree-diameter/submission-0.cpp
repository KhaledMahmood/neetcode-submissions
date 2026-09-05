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
    int diameterOfBinaryTree(TreeNode* root) {

        if(root == nullptr) return 0;

        int maxLen = 0;

        getMaxNode(root, maxLen);

        return maxLen;        
    }

    int getMaxNode(TreeNode* root, int& mxLen) {
        if(root == nullptr) return 0;
        if(root->right == nullptr && root->left == nullptr) return 1;

        int mxR = getMaxNode(root->right, mxLen);
        int mxL = getMaxNode(root->left, mxLen);

        int curr = (mxR + mxL);  //path count, so 1 less than node
        if(mxLen < curr) mxLen = curr;

        return max(mxR, mxL) + 1; //only max node len matters for upper layer
    }
};
