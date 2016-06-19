public class Solution {
    private void loop(int[][] matrix, int si, int sj, int rl, int cl, int dir, int count) {
        if (rl == 0 || cl == 0)
            return;
        int i;
        if (dir == 0) {
            for (i = sj; i < sj+cl; i++) {
                matrix[si][i] = count;
                count++;
            }
            loop(matrix, si+1, i-1, rl-1, cl, 1, count);
        } else if (dir == 1) {
            for (i = si; i < si+rl; i++) {
                matrix[i][sj] = count;
                count++;
            }
            loop(matrix, i-1, sj-1, rl, cl-1, 2, count);
        } else if (dir == 2) {
            for (i = sj; i > sj-cl; i--) {
                matrix[si][i] = count;
                count++;
            }
            loop(matrix, si-1, i+1, rl-1, cl, 3, count);
        } else if (dir == 3) {
            for (i = si; i > si-rl; i--) {
                matrix[i][sj] = count;
                count++;
            }
            loop(matrix, i+1, sj+1, rl, cl-1, 0, count);
        }
        return;
    }

    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        loop(matrix, 0, 0, n, n, 0, 1);
        return matrix;
    }
}
