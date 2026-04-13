class Solution {
public:
vector<vector<int>> out;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> x(nums.size(), false);
        backtrack(curr, nums, x);
        return out;
    }

    void backtrack(vector<int>& curr, vector<int>& nums, vector<bool> x){
        if(curr.size() == nums.size()){
            out.push_back(curr);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(!x[i]){
                curr.push_back(nums[i]);
                x[i] = true;
                backtrack(curr, nums, x);
                
                curr.pop_back();
                x[i] = false;
            }
        }
    }
};
