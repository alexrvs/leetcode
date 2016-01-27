class Solution {
public:
    bool isValid(vector<string> &board, int i, int j) {
        int size = board.size();
        int count = 0;
        printBoard(board);
        for (int k = 0; k < size; k++) {
            if (board[i][k] == 'Q') count++;
            if (board[k][j] == 'Q') count++;
            int r1 = i-(j-k);
            if (r1 >= 0 && r1 < size) {
                if (board[r1][k] == 'Q') count++;
            }
            int r2 = i+(j-k);
            if (r2 >= 0 && r2 < size) {
                if (board[r2][k] == 'Q') count++;
            }
        }
        if (count > 4) return false;
        //cout << "Pass" << endl;
        return true;
    }

    void printBoard(vector<string> &board) {
        int size = board.size();
        cout << "Board:" << endl;
        for (int i = 0; i < size; i++)
            cout << board[i] << endl;
    }

    void solveLoop(vector<string> &board, int n, vector<vector<string> > &result) {
        int size = board.size();
        int row = size - n;
        for (int i = 0; i < size; i++) {
            board[row][i] = 'Q';
            if (row == 0 || isValid(board, row, i)) {
                if (row == size - 1) {
                    vector<string> solution(board);
                    result.push_back(solution);
                } else {
                    solveLoop(board, n-1, result);
                }
            }
            board[row][i] = '.';
        }
        return;
    }
    int totalNQueens(int n) {
        vector<vector<string> > result;
        vector<string> board;
        string line = "";
        for (int i = 0; i < n; i++) {
            line += '.';
        }
        for (int i = 0; i < n; i++) {
            board.push_back(line);
        }
        solveLoop(board, n, result);
        return result.size();
    }
};
