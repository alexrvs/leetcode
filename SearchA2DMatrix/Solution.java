public class Solution {
    private int search(int[][] matrix, int target) {
        int h = matrix.length;
        int l = 0;
        int r = h;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (matrix[m][0] <= target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return r - 1;
    }

    private boolean searchRow(int[][] matrix, int i, int target) {
        if (i < 0) return false;
        int l = 0;
        int r = matrix[i].length;
        int m = 0;
        while (l < r) {

            m = l + (r - l) / 2;
            if (matrix[i][m] < target) {
                l = m + 1;
            } else if (matrix[i][m] == target) {
                return true;
            } else {
                r = m;
            }
        }
        return false;
    }

    public boolean searchMatrix(int[][] matrix, int target) {
        if (matrix.length == 0) return false;
        int i = search(matrix, target);
        return searchRow(matrix, i, target);
    }
}
