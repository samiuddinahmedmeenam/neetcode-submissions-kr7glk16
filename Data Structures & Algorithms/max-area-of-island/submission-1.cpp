class Solution {
   public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

       
        int m = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    m = max(m, count);
                }
            }
        }

        return m;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) {
            return;
        }

        grid[i][j] = 0;
        count++;
        for (int x = 0; x < 4; x++) {
            dfs(grid, i + directions[x][0], j + directions[x][1], count);
        }
    }
};
