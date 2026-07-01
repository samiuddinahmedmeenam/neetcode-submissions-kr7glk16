class Solution {
public:

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pac(row, vector<bool>(col, false));
        vector<vector<bool>> atl(row, vector<bool>(col, false));

        for(int c = 0; c<col; c++){
            dfs(0, c, pac, heights);
            dfs(row-1, c, atl, heights);
        }

        for(int r = 0; r<row; r++){
            dfs(r, 0, pac, heights);
            dfs(r, col-1, atl, heights);
        }

        vector<vector<int>> out;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(pac[i][j] && atl[i][j]){
                    out.push_back({i, j});
                }
            }
        }

        return out;
    }


    void dfs(int i, int j, vector<vector<bool>>& ocean, vector<vector<int>>& heights){
        ocean[i][j] = true;

        for(auto x: directions){
            int m = i + x[0];
            int n = j + x[1];

            if(m >= 0 && m < heights.size() && n >= 0 && n <heights[0].size() && !ocean[m][n] && heights[m][n] >= heights[i][j]){
                dfs(m, n, ocean, heights);
            }
        }
    }
};
