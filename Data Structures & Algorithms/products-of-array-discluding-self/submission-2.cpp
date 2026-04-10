class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> out(nums.size(), 1);

        int L = 1;
        int R = 1;

        for(int i = 0; i<nums.size(); i++){
            out[i] *= L;
            L *= nums[i];
        }

        for(int j = nums.size()-1; j>=0; j--){
            out[j] *= R;
            R *= nums[j];
        }

        return out;

    }
};
