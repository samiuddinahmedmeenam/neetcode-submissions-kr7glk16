class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> n(nums.begin(), nums.end());
        int longest = 0;

        for(int i = 0; i<nums.size(); i++){
            if(n.find(nums[i]-1) == n.end()){
                int length = 1;

                while(n.find(nums[i]+length) != n.end()){
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
        
    }
};
