class Solution {
private:
    void visit(vector<vector<char> >& board, int i, int h, int j, int w) {
        if (board[i][j] == 'O') {
            board[i][j] = 0;
            if (i > 1) visit(board, i - 1, h, j, w);
            if (i + 1 < h) visit(board, i + 1, h, j, w);
            if (j > 1) visit(board, i, h, j - 1, w);
            if (j + 1 < w) visit(board, i, h, j + 1, w);
        }
        return;
    }
    
    void mark(vector<vector<char> >& board, int h, int w) {
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] != 0) {
                    board[i][j] = 'X';
                } else {
                    board[i][j] = 'O';
                }
            }
        }
        return;
    }
    
public:
    void solve(vector<vector<char> >& board) {
        int h = board.size();
        if (h == 0) return;
        int w = board[0].size();
        for (int i = 0; i < h; i++) {
            visit(board, i, h, 0, w);
            visit(board, i, h, w - 1, w);
        }
        for (int j = 0; j < w; j++) {
            visit(board, 0, h, j, w);
            visit(board, h - 1, h, j, w);
        }
        mark(board, h, w);
        return;
    }
};