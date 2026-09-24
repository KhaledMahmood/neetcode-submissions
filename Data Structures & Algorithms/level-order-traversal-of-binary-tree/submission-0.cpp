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
    vector<vector<int>> levelOrder(TreeNode* root) {

        process(root, 1);

        vector<vector<int>> res;
        for(auto& [k, v]: nodes) {
            res.push_back(v);
        }

        return res;
    }

private:
    map<int, vector<int>> nodes;

    void process(TreeNode* root, int level) {

        if(root == nullptr) return;

        nodes[level].push_back(root->val);

        process(root->left, level + 1);
        process(root->right, level + 1);

    }

};
