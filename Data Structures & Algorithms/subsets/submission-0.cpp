class Solution {
public:

    void dfs(vector<vector<int>>& out, vector<int>& subset, vector<int>& nums, int i){
        if(i >= nums.size()){
            out.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(out, subset, nums, i+1);
        subset.pop_back();
        dfs(out, subset, nums, i+1);
    }



    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> out;
        vector<int> subset;

        dfs(out, subset, nums, 0);

        return out;
    }
};
