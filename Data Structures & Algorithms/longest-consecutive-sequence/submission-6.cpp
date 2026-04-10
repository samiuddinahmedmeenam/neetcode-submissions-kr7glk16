class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> S(nums.begin(), nums.end());

        int length = 0;
        int longest = 0;

        for(int i = 0; i<nums.size(); i++){
            if(S.find(nums[i]-1) == S.end()){
                length = 0;

                while(S.find(nums[i]+length) != S.end()){
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
        
    }
};
