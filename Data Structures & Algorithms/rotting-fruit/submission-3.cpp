class Solution {
public:

vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col =grid[0].size();

        int fresh = 0;
        int min  = 0;
        queue<pair<int, int>> rotten;

        for(int i =0;i<row;i++){
            for(int j=0;j<col; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    rotten.push({i, j});
                }
            }
        }

        while(!rotten.empty() && fresh > 0){
            int len = rotten.size();

            for(int i =0;i<len;i++){
                int m = rotten.front().first;
                int n = rotten.front().second;

                rotten.pop();

                for(auto x: directions){
                    int r = m +x[0];
                    int c = n+x[1];

                    if(r<0 || c<0 || r>= grid.size() || c>= grid[0].size() || grid[r][c] != 1){
                        continue;
                    }else{
                        fresh--;
                        rotten.push({r, c});
                        grid[r][c] = 2;
                    }
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
