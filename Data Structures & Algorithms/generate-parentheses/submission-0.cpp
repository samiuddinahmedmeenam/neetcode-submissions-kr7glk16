class Solution {
public:

    void generate(vector<string>& out, int open, int close, string curr){
        if(open == 0 && close == 0){
            out.push_back(curr);
            return;
        }

        if(open>0){
            generate(out, open-1, close, curr+"(");
        }if(close>open){
            generate(out, open, close-1, curr+")");
        }
        
    }

    vector<string> generateParenthesis(int n) {

        vector<string> out;
        generate(out, n, n, "");
        return out;
        
    }
};
