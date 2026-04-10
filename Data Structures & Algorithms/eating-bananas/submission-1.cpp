class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int out = r;

        while(l<=r){
            int mid = (l+r)/2;
            int time = 0;

            for(auto x: piles){
                time += ceil(static_cast<double>(x)/mid);
            }

            if(time <= h){
                out = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }

        return out;
        
    }
};
