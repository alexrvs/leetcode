public class Solution {
    public boolean isValidSudoku(char[][] board) {
        int size = board.length;
        int[] rowNums = new int[size];
        int[] colNums = new int[size];
        int[] gridNums = new int[size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                int gridNum = (i / 3) * 3 + j / 3;
                if (board[i][j] != '.') {
                    int val = 0x0001 << (board[i][j] - '0');
                    if ((rowNums[i] & val) != 0 || (colNums[j] & val) != 0|| (gridNums[gridNum] & val) != 0) {
                        return false;
                    } else {
                        rowNums[i] |= val;
                        colNums[j] |= val;
                        gridNums[gridNum] |= val;
                    }
                }
            }
        }
        return true;
    }
}
