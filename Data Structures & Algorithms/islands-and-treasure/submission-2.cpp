class Solution {
public:

vector<vector<int>> direction = {{0, 1} ,{0, -1}, {1, 0}, {-1, 0}};
int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> Q;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 0){
                    Q.push({i, j});
                }
            }
        }

        while(!Q.empty()){
            int r = Q.front().first;
            int c = Q.front().second;
            Q.pop();

            for(int x = 0; x<4; x++){
                int m = r + direction[x][0];
                int n = c + direction[x][1];

                if(m<0 || n<0 || m>=grid.size() || n>=grid[0].size() || grid[m][n] != INF){
                    continue;
                }

                grid[m][n] = grid[r][c]+1;
                Q.push({m, n});
            }
        }
    }
};
