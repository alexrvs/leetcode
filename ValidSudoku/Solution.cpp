class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        vector<vector<bool> > rowNums(9, vector<bool>(9, false));
        vector<vector<bool> > colNums(9, vector<bool>(9, false));
        vector<vector<bool> > gridNums(9, vector<bool>(9, false));

        int size = board.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int gridIdx = (i/3)*3+j/3;
                if (board[i][j] != '.') {
                    int val = board[i][j] - '1';
                    if (rowNums[i][val] || colNums[j][val] || gridNums[gridIdx][val]) {
                        return false;
                    } else {
                        rowNums[i][val] = true;
                        colNums[j][val] = true;
                        gridNums[gridIdx][val] = true;
                    }
                }
            }
        }
        return true;
    }
};
