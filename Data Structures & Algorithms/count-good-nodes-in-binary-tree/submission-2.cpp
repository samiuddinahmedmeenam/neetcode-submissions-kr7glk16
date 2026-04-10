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

    void dfs(TreeNode* root, TreeNode* node, int& count, int maximum){


        if(!node) return;

        if(node->val >= maximum){
            maximum = max(maximum, node->val);
            count++;
        }

        dfs(root, node->left, count, maximum);
        dfs(root, node->right, count, maximum);
    }



    int goodNodes(TreeNode* root) {

        if(!root) return 0;

        int count = 1;
        int maximum = root->val;

        dfs(root, root->left, count, maximum);
        dfs(root, root->right, count, maximum);

    return count;

        
    }
};
