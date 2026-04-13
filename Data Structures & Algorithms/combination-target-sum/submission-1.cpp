class Solution {
public:
vector<vector<int>> out;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(curr, nums, target, 0, 0);
        return out;
    }

    void backtrack(vector<int>& curr, vector<int>& nums, int& target, int total, int i){
        if(total == target){
            out.push_back(curr);
            return;
        }

        if(total > target || i>=nums.size()){
            return;
        }

        curr.push_back(nums[i]);
        backtrack(curr, nums, target, total+nums[i], i);
        curr.pop_back();
        backtrack(curr, nums, target, total, i+1);
    }
};
