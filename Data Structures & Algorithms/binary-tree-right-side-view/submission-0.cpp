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
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};

        vector<int> out;

        queue<TreeNode*> Q;
        Q.push(root);

        while(!Q.empty()){
            TreeNode* rightSide = nullptr;
            int len = Q.size();

            for(int i = 0; i<len; i++){
                TreeNode* node = Q.front();
                Q.pop();

                if(node){
                    rightSide = node;
                    if(node->left) Q.push(node->left);
                    if(node->right) Q.push(node->right);
                }
            }
            if(rightSide){
                out.push_back(rightSide->val);
            }
        }

        return out;


        
    }
};
