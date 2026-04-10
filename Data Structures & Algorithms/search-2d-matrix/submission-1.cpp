class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int r = matrix.size();
        int c = matrix[0].size();

        int a = 0;
        int b = c - 1;

        while(a<r && b>=0){
            if(matrix[a][b] == target) return true;
            else if(matrix[a][b] > target) b--;
            else if(matrix[a][b] < target) a++;
        }

        return false;
        
    }
};
