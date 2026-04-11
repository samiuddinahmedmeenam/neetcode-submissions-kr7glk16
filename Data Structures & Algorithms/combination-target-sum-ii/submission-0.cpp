class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int>>& out, vector<int>& curr, int target, int i, int total){

        if(total == target){
            out.push_back(curr);
            return;
        }

        if(total > target || i >= nums.size()){
            return;
        }

        curr.push_back(nums[i]);
        backtrack(nums, out, curr, target, i+1, total+nums[i]);
        curr.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]){
            i++;
        }

        backtrack(nums, out, curr, target, i+1, total);
    }



    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> out;
        vector<int> curr;

        backtrack(candidates, out, curr, target, 0, 0);

        return out;
        
    }
};
