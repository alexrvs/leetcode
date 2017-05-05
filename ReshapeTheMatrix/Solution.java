public class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int nums_r = nums.length;
        if (nums_r == 0) {
            return nums;
        }
        int nums_c = nums[0].length;
        if (nums_r * nums_c < r * c) {
            return nums;
        }
        int[][] res = new int[r][c];
        int idx = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                idx = c * i + j;
                res[i][j] = nums[idx / nums_c][idx % nums_c];
            }
        }
        return res;
    }
}