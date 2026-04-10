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

    void dfs(TreeNode*& root, TreeNode*& node, int& out,int maximum){
        if(!node) return;

        if(node->val >= maximum){
            maximum = max(maximum, node->val);
            out++;
        }       

        dfs(root, node->left, out, maximum);
        dfs(root, node->right, out, maximum); 
        
    }



    int goodNodes(TreeNode* root) {

        if(!root) return 0;

        int out = 1;
        int maximum = root->val;

        TreeNode* node = root;

        dfs(node, root->left, out, maximum);
        dfs(node, root->right, out, maximum);

        return out;
    }
};
