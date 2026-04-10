class Solution {
public:

    void check(vector<int>& temperatures, int& i, int& temp, stack<int>& stk){
        int count = 1;
        for(int j = i+1; j<temperatures.size(); j++){
            if(temperatures[j] <= temp){
                count++;
            }else{
                stk.push(count);
                return;
            }
        }
        stk.push(0);
        return;
    }



    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<int> stk;

        for(int i = 0; i<temperatures.size(); i++){
            check(temperatures, i, temperatures[i], stk);
        }

        vector<int> out;
        while(!stk.empty()){
            out.push_back(stk.top());
            stk.pop();
        }

        reverse(out.begin(), out.end());

        return out;
        
    }
};
