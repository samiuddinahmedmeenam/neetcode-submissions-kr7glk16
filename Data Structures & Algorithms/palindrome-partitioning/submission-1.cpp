class Solution {
public: 
vector<vector<string>> out;




    vector<vector<string>> partition(string s) {
        vector<string> curr;
        backtrack(curr, s, 0, 0);
        return out;
    }

    void backtrack(vector<string>& curr, string& s, int i, int j){
        if(i >= s.size()){
            if(i == j){
                out.push_back(curr);
                return;
            }
        }

        if(j==s.size()) return;

        if(isPal(s, i, j)){
            curr.push_back(s.substr(i, j-i+1));
            backtrack(curr, s, j+1, j+1);
            curr.pop_back();
        }

        backtrack(curr, s, i, j+1);
    }

    bool isPal(string& s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};
