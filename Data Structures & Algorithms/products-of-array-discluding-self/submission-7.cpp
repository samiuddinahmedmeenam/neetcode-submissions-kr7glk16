class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int left = 1;
        int right = 1;

        vector<int> out(nums.size(), 1);

        for(int i = 0; i<nums.size(); i++){
            out[i] *= left;
            left *= nums[i];
        }

        for(int j = nums.size()-1; j>=0; j--){
            out[j] *= right;
            right *= nums[j];
        }

        return out;
    }
};
