public class Solution {
    public int missingNumber(int[] nums) {
        int x = nums[0];
        for (int i = 1; i < nums.length; i++) {
            x ^= nums[i];
        }
        for (int i = 0; i <= nums.length; i++) {
            x ^= i;
        }
        return x;
    }
}
