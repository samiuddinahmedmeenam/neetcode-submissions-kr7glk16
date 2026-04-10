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
        
      

        queue<TreeNode*> Q;
        Q.push(root);

        vector<vector<int>> out;

        while(!Q.empty()){
            vector<int> temp;
            int x = Q.size();

            for(int i = 0; i<x; i++){
                TreeNode* node = Q.front();
                Q.pop();

                if(node){
                    temp.push_back(node->val);
                    if(node->left) Q.push(node->left);
                    if(node->right) Q.push(node->right);
                }
            }
            if(!temp.empty()){
                out.push_back(temp);
            }
        }

        return out;
    }
};
