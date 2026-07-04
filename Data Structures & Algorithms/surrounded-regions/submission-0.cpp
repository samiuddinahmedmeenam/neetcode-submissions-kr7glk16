class Solution {
   public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for (int i = 0; i < row; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0);
            }
            if (board[i][col - 1] == 'O') {
                dfs(board, i, col - 1);
            }
        }

        for (int j = 0; j < col; j++) {
            if (board[0][j] == 'O') {
                dfs(board, 0, j);
            }
            if (board[row - 1][j] == 'O') {
                dfs(board, row - 1, j);
            }
        }

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }


    void dfs(vector<vector<char>>& board, int i, int j){

        board[i][j] = 'T';

        for(auto x: directions){
            int r = i+x[0];
            int c = j+x[1];

            if(r<0 || c<0 || r>=board.size() || c >= board[0].size() || board[r][c] != 'O'){
                continue;
            }
            dfs(board, r, c);
        }
    }
};
