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

    vector<vector<int>> nodes;

public:
    vector<int> rightSideView(TreeNode* root) {

        process(root, 0);

        vector<int> res;

        for(auto& v: nodes) {
            res.push_back(v[0]);
        }

        return res;
    }

    void process(TreeNode* root, int level) {
        if(root == nullptr) {
            return;
        }

        if(nodes.size() == level) {
            nodes.push_back({root->val});
        } else{
            nodes[level].push_back(root->val);
        }

        process(root->right, level + 1);
        process(root->left, level + 1);

    }
};
