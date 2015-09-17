public class Solution {
    public int rob(int[] nums) {
        int size = nums.length;
        if (size == 0) return 0;
        if (size == 1) return nums[0];
        int pred, sum, max;
        for (int i = 1; i < size; i++) {
            pred = i > 4 ? i - 4 : 0;
            max = nums[i];
            for (int j = pred; j < i - 1; j++) {
                sum = nums[i] + nums[j];
                if (max < sum) max = sum;
            }
            nums[i] = max;
        }
        return nums[size - 1] > nums[size - 2] ? nums[size - 1] : nums[size - 2];
    }
}
