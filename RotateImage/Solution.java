public class Solution {
    public void rotate(int[][] matrix) {
        int l = matrix.length;
        int h = l / 2;
        int w = h;
        if (l % 2 != 0) w++;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[l - 1 - j][i];
                matrix[l - 1 - j][i] = matrix[l - 1 - i][l - 1 - j];
                matrix[l - 1 - i][l - 1 - j] = matrix[j][l - 1 - i];
                matrix[j][l - 1 - i] = tmp;
            }
        }
    }
}
