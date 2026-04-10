class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> stack;

        for(auto c: tokens){
            if(c == "+"){
                int num1 = stack.top(); stack.pop();
                int num2 = stack.top(); stack.pop();
                stack.push(num2+num1);
            }else if(c == "-"){
                int num1 = stack.top(); stack.pop();
                int num2 = stack.top(); stack.pop();
                stack.push(num2-num1);
            }else if(c == "*"){
                int num1 = stack.top(); stack.pop();
                int num2 = stack.top(); stack.pop();
                stack.push(num2 * num1);
            }else if(c == "/"){
                int num1 = stack.top(); stack.pop();
                int num2 = stack.top(); stack.pop();
                stack.push(num2/num1);
            }else{
                stack.push(stoi(c));
            }
        }

        return stack.top();
        
    }
};
