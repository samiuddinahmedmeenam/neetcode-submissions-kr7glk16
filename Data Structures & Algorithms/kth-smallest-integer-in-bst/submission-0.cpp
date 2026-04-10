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

    void dfs(TreeNode* root, vector<int>& list){
        if(!root) return;

        list.push_back(root->val);
        if(root->left) dfs(root->left, list);
        if(root->right) dfs(root->right, list);
    }





    int kthSmallest(TreeNode* root, int k) {

        vector<int> list;

        dfs(root, list);

        sort(list.begin(), list.end());

        return list[k-1];
        
    }
};
