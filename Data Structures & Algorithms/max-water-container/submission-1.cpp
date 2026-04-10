class Solution {
public:
    int maxArea(vector<int>& heights) {

        int l = 0;
        int r = heights.size() -1;

        int water = 0;
        int x = 0;

        while(l<r){

            if(heights[l] <= heights[r]){
                int diff = r - l;
                x = diff * heights[l];
                water = max(water, x);
                l++;
            }else if(heights[l] > heights[r]){
                int diff = r - l;
                x = diff * heights[r];
                water = max(water, x);
                r--;
            }
        }
        return water;
    }

    
};
