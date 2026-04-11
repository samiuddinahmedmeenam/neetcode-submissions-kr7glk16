class Solution {
public:

    int row;
    int col;
    set<pair<int, int>> path;


    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int i){

        if(i == word.size()){
            return true;
        }

        if(r < 0 || c < 0 || r >= row || c >= col || board[r][c] != word[i] || path.count({r, c})){
            return false;
        }

        path.insert({r, c});
        bool x = backtrack(board, word, r+1, c, i+1) || 
                 backtrack(board, word, r-1, c, i+1) ||
                 backtrack(board, word, r, c+1, i+1) ||
                 backtrack(board, word, r, c-1, i+1);

        path.erase({r, c});
        
        return x;
    }



    bool exist(vector<vector<char>>& board, string word) {

        

        row = board.size();
        col = board[0].size();

        for(int r = 0; r<row; r++){
            for(int c = 0; c<col; c++){
                if(backtrack(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
        
    }
};
