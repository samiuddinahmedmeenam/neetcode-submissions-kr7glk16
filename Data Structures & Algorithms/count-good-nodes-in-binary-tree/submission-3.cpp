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

    void dfs(TreeNode* root, TreeNode* node, int& out, int x){
        if(!node) return;

        if(node->val >= x){
            x = max(x, node->val);
            out++;
        }

        dfs(root, node->left, out, x);
        dfs(root, node->right, out, x);
    }



    int goodNodes(TreeNode* root) {

        int out = 1;
        int x = root->val;

        dfs(root, root->left, out, x);
        dfs(root, root->right, out, x);

        return out;
        
    }
};
