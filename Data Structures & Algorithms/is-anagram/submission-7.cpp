class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        vector<int> out(26, 0);

        for(int i = 0; i<s.size(); i++){
            out[s[i] - 'a']++;
        }

        for(int j = 0; j<t.size(); j++){
            out[t[j] - 'a']--;
        }

        for(auto x: out){
            if(x != 0){
                return false;
            }
        }

        return true;
        
    }
};
