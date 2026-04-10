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
        int depth = 0;
        dfs(root, depth);
        return depth;
    }

    int dfs(TreeNode* root, int& depth){

        if(!root) return 0;
        
        int left = dfs(root->left, depth);
        int right = dfs(root->right, depth);

        depth = max(depth, left+right);

        return 1 + max(left, right);
    }
};
