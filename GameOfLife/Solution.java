public class Solution {
    private boolean isLive(int[][] board, int i, int j, int row, int col) {
        int cnt = 0;
        for (int r = -1; r <=1; r++) {
            for (int c = -1; c <= 1; c++) {
                if (r == 0 && c == 0) continue;
                if (i + r >= 0 && i + r < row &&
                    j + c >= 0 && j + c < col && (board[i + r][j + c] & 0x0001) > 0) {
                        cnt++;
                    }
            }
        }
        if (cnt == 2 && board[i][j] == 1) return true;
        if (cnt == 3) return true;
        return false;
    }

    public void gameOfLife(int[][] board) {
        int r = board.length;
        if (r == 0) return;
        int c = board[0].length;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isLive(board, i, j, r, c)) {
                    board[i][j] += 2;
                }
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] >>= 1;
            }
        }
        return;
    }
}
