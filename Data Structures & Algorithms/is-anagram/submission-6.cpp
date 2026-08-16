class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        vector<int> check(26, 0);

        for(int i = 0; i<s.size(); i++){
            check[s[i] - 'a']++;
        }

        for(int j = 0; j<t.size(); j++){
            check[t[j] - 'a']--;
        }

        for(auto x: check){
            if(x != 0){
                return false;
            }
        }

        return true;
    }
};
