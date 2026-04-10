class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> map = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> stk;

        for(int i = 0; i<s.size(); i++){
            if(map.count(s[i])){
                if(!stk.empty() && stk.top() == map[s[i]]){
                    stk.pop();
                }else{
                    return false;
                }
            }else{
                stk.push(s[i]);
            }
        }

        return stk.empty();
        
    }
};
