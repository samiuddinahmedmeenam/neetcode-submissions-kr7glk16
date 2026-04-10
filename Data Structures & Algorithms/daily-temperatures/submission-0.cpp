class Solution {
public:

    void check(stack<int>& stack, vector<int>& temperatures, int i){
        int count = 1;
        for(int a = i+1; a<temperatures.size(); a++){
            if(temperatures[i] >= temperatures[a]){
                count++;
            }else if(temperatures[i] < temperatures[a]){
                stack.push(count);
                return;
            }
        }
        stack.push(0);
        return;
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> stack;

        for(int i = 0; i<temperatures.size(); i++){
            check(stack, temperatures, i);
        }

        vector<int> out;
        while(!stack.empty()){
            out.push_back(stack.top());
            stack.pop();
        }

        reverse(out.begin(), out.end());

        return out;
        
    }
};
