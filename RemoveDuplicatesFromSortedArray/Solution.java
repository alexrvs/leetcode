public class Solution {
    public int removeDuplicates(int[] nums) {
        int size = nums.length;
        if (size <= 1) return size;
        int len = 1;
        int lastValue = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] != lastValue) {
                lastValue = nums[i];
                nums[len++] = nums[i];
            }
        }
        return len;
    }
}
