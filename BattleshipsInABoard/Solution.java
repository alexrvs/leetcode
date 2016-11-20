public class Solution {
    public int countBattleships(char[][] board) {
        int h = board.length;
        if (h == 0) return 0;
        int w = board[0].length;
        int cnt = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == 'X') {
                    if ((i + 1 >= h || board[i + 1][j] != 'X') && 
                        (j + 1 >= w || board[i][j + 1] != 'X')) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
}