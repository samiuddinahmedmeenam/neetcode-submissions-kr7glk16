class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;

        vector<int> n(26, 0);

        for(int i = 0; i<s.size(); i++){
            n[s[i] - 'a']++;
            n[t[i] - 'a']--;
        }

        for(int i: n){
            if(i != 0){
                return false;
            }
        }

        return true;
        
    }
};
