class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        vector<pair<int, int>> list;
        for(int i = 0; i<position.size(); i++){
            list.push_back({position[i], speed[i]});
        }

        sort(list.rbegin(), list.rend());

        vector<double> out;

        for(auto& p: list){
            out.push_back((double)(target-p.first)/p.second);
            if(out.size() >= 2 && out.back() <= out[out.size()-2]){
                out.pop_back();
            }
        }

        return out.size();
        
    }
};
