class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stack;
        unordered_map<char, char> map = {  {')', '('}, {']', '['}, {'}', '{'}  };

        for(int i = 0; i<s.size(); i++){
            if(map.count(s[i])){
                if(!stack.empty() && stack.top() == map[s[i]]){
                    stack.pop();
                }else{
                    return false;
                }
            }else{
                stack.push(s[i]);
            }
        }

        return stack.empty();
    }
};
