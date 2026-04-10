class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()){
            return false;
        }

        vector<int> str(26, 0);
        for(int i = 0; i<s.size(); i++){
            str[s[i] - 'a']++;
            str[t[i] - 'a']--;
        }

        for(int X: str){
            if(X != 0){
                return false;
            }
        }
        
        return true;
    }
};
