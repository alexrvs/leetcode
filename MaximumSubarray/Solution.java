public class Solution {
    public int maxSubArray(int[] nums) {
        int size = nums.length;
        if (size == 0) return 0;
        int sum = nums[0];
        int max = nums[0];
        for (int i = 1; i < size; i++) {
            sum += nums[i];
            if (sum < nums[i]) {
                sum = nums[i];
            }
            if (max < sum) {
                max = sum;
            }
        }
        return max;
    }
}
