class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};


    void backtrack(string& digits, string curr, int i){
        if(curr.size() == digits.size()){
            res.push_back(curr);
            return;
        }

        string x = digitToChar[digits[i] - '0'];
        for(char c: x){
            backtrack(digits, curr+c, i+1);
        }
    }





    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;

        backtrack(digits, "", 0);
        return res;

    }
};
