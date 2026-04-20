class Solution {
public:
int directions[4][2] = {{-1, 0}, {+1, 0}, {0, -1}, {0, +1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int fresh = 0;
        queue<pair<int, int>> Q;
        int min = 0;

        for(int i = 0; i<row; i++){
            for(int j = 0; j<col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    Q.push({i, j});
                }
            }
        }

        while(!Q.empty() && fresh > 0){
            int len = Q.size();
            
            for(int i = 0; i<len; i++){
                int m = Q.front().first;
                int n = Q.front().second;
                Q.pop();

                for(int i = 0; i<4; i++){
                    int r = m+directions[i][0];
                    int c = n+directions[i][1];

                    if(r<0 || c<0 || r>=row || c>=col || grid[r][c] != 1){
                        continue;
                    }

                    grid[r][c] = 2;
                    fresh--;
                    Q.push({r, c});
                }
            }
            min++;
        }

        if(fresh == 0){
            return min;
        }else{
            return -1;
        }
    }
};
