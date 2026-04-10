class TimeMap {
public:
    
    unordered_map<string, vector<pair<string, int>>> map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        
        auto& v = map[key];
        string out = "";

        int l = 0;
        int r = v.size()-1;

        while(l<=r){
            int mid = (l+r)/2;

            if(v[mid].second <= timestamp){
                out = v[mid].first;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return out;
    }
};
