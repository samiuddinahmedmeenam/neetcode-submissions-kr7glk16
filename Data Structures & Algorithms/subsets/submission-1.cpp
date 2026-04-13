class Solution {
public:

vector<vector<int>> out;

    void backtrack(vector<int>& curr, vector<int>& nums, int i){
        if(i >= nums.size()){
            out.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        backtrack(curr, nums, i+1);
        curr.pop_back();
        backtrack(curr, nums, i+1);
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(curr, nums, 0);
        return out;
    }
};
