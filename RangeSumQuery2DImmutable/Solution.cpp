class NumMatrix {
private:
    vector<vector<int>> sum;
    int m_row;
    int m_col;

public:
    NumMatrix(vector<vector<int>> &matrix) {
        m_row = matrix.size();
        if (m_row == 0) return;
        m_col = matrix[0].size();
        if (m_col == 0) return;
        for (int r = 0; r < m_row; r++) {
            sum.push_back(vector<int>(m_col, 0));
            for (int c = 0; c < m_col; c++) {
                if (r == 0 && c == 0) sum[r][c] = matrix[r][c];
                else if (r == 0) sum[r][c] += sum[r][c - 1] + matrix[r][c];
                else if (c == 0) sum[r][c] += sum[r - 1][c] + matrix[r][c];
                else sum[r][c] = sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1] + matrix[r][c];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 >= m_row || row2 >= m_row || col1 >= m_col || col2 >= m_col) return 0;
        if (row1 == 0 && col1 == 0) return sum[row2][col2];
        else if (row1 == 0) return sum[row2][col2] - sum[row2][col1 - 1];
        else if (col1 == 0) return sum[row2][col2] - sum[row1 - 1][col2];
        else return sum[row2][col2] + sum[row1 - 1][col1 - 1] - sum[row2][col1 - 1] -sum[row1 - 1][col2];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
