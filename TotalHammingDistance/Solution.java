public class Solution {
    public int totalHammingDistance(int[] nums) {
        int[][] cnt = new int[32][2];
        int size = nums.length;
        int mask = 0x1;
        for (int i = 0; i < size; i++) {
            int tmp = nums[i];
            for (int j = 0; j < 32; j++) {
                if ((tmp & mask) == 0) {
                    cnt[j][0]++;
                } else {
                    cnt[j][1]++;
                }
                tmp >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += cnt[i][0] * cnt[i][1];
        }
        return res;
    }
}