class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int l = 1;
        int r = 1;

        vector<int> out(nums.size(), 1);

        for(int i = 0; i<nums.size(); i++){
            out[i] *= l;
            l *= nums[i];
        }

        for(int j = nums.size()-1; j>= 0; j--){
            out[j] *= r;
            r *= nums[j];
        }

        return out;

    }
};
