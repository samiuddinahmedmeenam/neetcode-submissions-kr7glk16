class Solution {
public:

    vector<vector<int>> out;

    void backtrack(vector<int>& nums, vector<int>& curr, vector<bool> x){

        if(curr.size() == nums.size()){
            out.push_back(curr);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(!x[i]){
                curr.push_back(nums[i]);
                x[i] = true;
                backtrack(nums, curr, x);

                curr.pop_back();
                x[i] = false;
            }
        }
    }






    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> x(nums.size(), false);

        backtrack(nums, curr, x);

        return out;

        
    }
};
