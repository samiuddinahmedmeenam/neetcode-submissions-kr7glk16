class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int>>& out, vector<int>& current, int target, int i){
        if(target == 0){
            out.push_back(current);
            return;
        }

        if(target < 0 || i >= nums.size()){
            return;
        }

        current.push_back(nums[i]);
        backtrack(nums, out, current, target-nums[i], i);
        current.pop_back();
        backtrack(nums, out, current, target, i+1);
    }




    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> out;
        vector<int> current;

        backtrack(nums, out, current, target, 0);

        return out;
    }
};
