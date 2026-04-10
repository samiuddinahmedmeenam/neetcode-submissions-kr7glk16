class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> list(26, 0);

        for(int i = 0; i<s.size(); i++){
            list[s[i] - 'a']++;
            list[t[i] - 'a']--;
        }

        for(auto x: list){
            if(x != 0){
                return false;
            }
        }

        return true;
        
    }
};
