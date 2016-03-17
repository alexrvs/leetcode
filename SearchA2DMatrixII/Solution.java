public class Solution {
    private boolean searchRow(int[] row, int target) {
        int l = 0;
        int r = row.length;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (row[m] < target) {
                l = m + 1;
            } else if (row[m] == target) {
                return true;
            } else {
                r = m;
            }
        }
        return false;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        int l = 0;
        int r = matrix.length;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        for (int i = l - 1; i >= 0; i--) {
            if (searchRow(matrix[i], target)) return true;
        }
        return false;
    }
}
