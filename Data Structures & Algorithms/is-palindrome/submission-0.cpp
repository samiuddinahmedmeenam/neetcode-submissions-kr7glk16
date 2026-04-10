class Solution {
public:
    bool is_char(char c){
        if(c >= 'A' && c <= 'Z' || 
           c >= 'a' && c <= 'z' || 
           c >= '0' && c <= '9'){
            return true;
           }else{
            return false;
           }
    }

    bool isPalindrome(string s) {
        int l = 0; int r = s.size()-1;

        while(l < r){
            while(l < r && !is_char(s[l])){
                l++;
            }
            while(r > l && !is_char(s[r])){
                r--;
            }
            if(tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }

        return true;
    }
};
