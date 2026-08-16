class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> maps;

        for(int i = 0; i<strs.size(); i++){
            string x = strs[i];
            sort(x.begin(), x.end());
            maps[x].push_back(strs[i]);
        }

        vector<vector<string>> out;
        
        for(auto& [k, v]: maps){
            out.push_back(v);
        }

        return out;
    }
};
