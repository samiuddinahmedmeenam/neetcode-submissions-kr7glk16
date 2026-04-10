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

            TreeNode* rightside = nullptr;
 
            int len = Q.size();

            for(int i = 0; i<len; i++){
                rightside = Q.front();
                Q.pop();

                if(rightside->left) Q.push(rightside->left);
                if(rightside->right) Q.push(rightside->right);
            }

            if(rightside){
                out.push_back(rightside->val);
            }
        }

        return out;
        
    }
};
