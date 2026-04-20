class Solution {
public:

int directions[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};
int row;
int col;
int INF = 2147483647;

    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> Q;
        row = grid.size();
        col = grid[0].size();

        for(int i = 0;i<row; i++){
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

            for(int i = 0; i<4; i++){
                int m = r+directions[i][0];
                int n = c+directions[i][1];

                if(m<0 || n<0 || m>=row || n>=col || grid[m][n] != INF){
                    continue;
                }

                grid[m][n] = grid[r][c]+1;
                Q.push({m, n});
            }
        }
    }
};
