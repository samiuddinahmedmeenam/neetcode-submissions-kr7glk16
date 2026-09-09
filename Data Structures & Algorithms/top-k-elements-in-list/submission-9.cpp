class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        unordered_map<int, int> maps;

        for(int i = 0; i<nums.size() ;i++){
            maps[nums[i]]++;
        }

        priority_queue<pair<int, int>> Q;
        for(auto [num, freq]: maps){
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
