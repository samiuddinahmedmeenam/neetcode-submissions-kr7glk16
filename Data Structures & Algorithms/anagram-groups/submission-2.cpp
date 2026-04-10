class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> map;

        for(auto x: strs){
            string s = x;
            sort(s.begin(), s.end());

            map[s].push_back(x);
        }

        vector<vector<string>> out;

        for(auto [k, v]: map){
            out.push_back(v);
        }

        return out;
        
    }
};
