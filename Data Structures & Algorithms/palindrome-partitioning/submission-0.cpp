class Solution {
public:

    void backtrack(vector<vector<string>>& out, vector<string>& curr, string& s, int i, int j){
        if(i >= s.size()){
            if(i == j){
                out.push_back(curr);
                return;
            }
        }

        if(j==s.size()){
            return;
        }

        if(ispal(s, i, j)){
            curr.push_back(s.substr(i, j-i+1));
            backtrack(out, curr, s, j+1, j+1);
            curr.pop_back();
        }

        backtrack(out, curr, s, i, j+1);
    }


    bool ispal(string& s, int l, int r){
        while(l < r){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }



    vector<vector<string>> partition(string s) {

        vector<vector<string>> out;
        vector<string> curr;

        backtrack(out, curr, s, 0, 0);

        return out;
        
    }
};
