class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stk;

        for(auto x: tokens){
            if(x == "+"){
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();
                stk.push(num2+num1);
            }
            else if(x == "-"){
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();
                stk.push(num2-num1);
            }
            else if(x == "*"){
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();
                stk.push(num2*num1);
            }
            else if(x == "/"){
                int num1 = stk.top(); stk.pop();
                int num2 = stk.top(); stk.pop();
                stk.push(num2/num1);
            }
            else{
                stk.push(stoi(x));
            }
        }

        return stk.top();
        
    }
};
