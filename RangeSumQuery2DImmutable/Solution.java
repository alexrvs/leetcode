public class NumMatrix {
    private int[][] sum;
    private int row;
    private int col;

    public NumMatrix(int[][] matrix) {
        this.row = matrix.length;
        if (row == 0) return;
        this.col = matrix[0].length;
        if (col == 0) return;
        sum = new int[row][col];
        sum[0][0] = matrix[0][0];
        for (int r = 1; r < row; r++) sum[r][0] = sum[r - 1][0] + matrix[r][0];
        for (int c = 1; c < col; c++) sum[0][c] = sum[0][c - 1] + matrix[0][c];
        for (int r = 1; r < row; r++) {
            for (int c = 1; c < col; c++) {
                sum[r][c] = sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1] + matrix[r][c];
            }
        }
    }

    public int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 >= row || row2 >= row || col1 >= col || col2 >= col) return 0;
        if (row1 == 0 && col1 == 0) return sum[row2][col2];
        else if (row1 == 0) return sum[row2][col2] - sum[row2][col1 - 1];
        else if (col1 == 0) return sum[row2][col2] - sum[row1 - 1][col2];
        else return sum[row2][col2] + sum[row1 - 1][col1 - 1] - sum[row2][col1 - 1] -sum[row1 - 1][col2];
    }
}


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix = new NumMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
