class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>> Q;

        for(auto [nums, freq] : map){
            Q.push({freq, nums});
        }

        vector<int> out;
        for(int i = 0; i<k; i++){
            out.push_back(Q.top().second);
            Q.pop();
        }

        return out;
        
    }
};
