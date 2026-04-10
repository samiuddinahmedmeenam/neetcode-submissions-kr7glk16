class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());\
        int out = r;

        while(l<=r){
            int k = (r+l) / 2;
            long long time = 0;
            for(int x: piles){
                time += ceil(static_cast<double>(x)/k);
            }

            if(time <= h){
                out = k;
                r = k-1;
            }else{
                l = k+1;
            }
        }

        return out;
        
    }
};
