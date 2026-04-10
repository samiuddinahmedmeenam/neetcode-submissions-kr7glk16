class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;

        for(auto X: nums){
            map[X]++;
            if(map[X] > 1){
                return X;
            }
        }
        
    }
};
