class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> map;

        for(auto x: nums){
            map[x]++;
        }

        priority_queue<pair<int, int>> Q;

        for(auto [num, freq]: map){
            Q.push({freq, num});
        }

        vector<int> out;
        for(int i = 0; i<k; i++){
            out.push_back(Q.top().second);
            Q.pop();
        }

        return out;
        
    }
};
