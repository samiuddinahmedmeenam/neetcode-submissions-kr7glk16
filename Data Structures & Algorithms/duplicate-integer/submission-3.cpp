class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;

        for(int n : nums){
            map[n]++;
            if(map[n] > 1){
                return true;
            }
        }

        return false;
        
    }
};