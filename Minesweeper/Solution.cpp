class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> clicks;
        clicks.push_back(click);
        int s = 0;
        int r = board.size();
        int c = board[0].size();
        while (s < clicks.size()) {
            int i = clicks[s][0];
            int j = clicks[s][1];
            if (board[i][j] == 'M') {
                board[i][j] = 'X';
                return board;
            } else if (board[i][j] == 'E') {
                int cnt = 0;
                vector<vector<int>> canClick;
                for (int ii = -1; ii <= 1; ii++) {
                    for (int jj = -1; jj <= 1; jj++) {
                        if (i + ii >= 0 && i + ii < r && 
                            j + jj >= 0 && j + jj < c) {
                            if (board[i + ii][j + jj] == 'M') cnt++;
                            vector<int> newClick;
                            newClick.push_back(i + ii);
                            newClick.push_back(j + jj);
                            canClick.push_back(newClick);
                        }
                    }
                }
                if (cnt > 0) {
                    board[i][j] = '0' + cnt;
                } else {
                    board[i][j] = 'B';
                    clicks.insert(clicks.end(), canClick.begin(), canClick.end());
                }
            }
            s++;
        }
        return board;
    }
};