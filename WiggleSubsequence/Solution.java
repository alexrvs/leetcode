public class Solution {
    public int wiggleMaxLength(int[] nums) {
        int size = nums.length;
        if (size <= 1) return size;
        int comm = nums[0];
        int len = 1;
        int prev = 0;
        for (int i = 1; i < size; i++) {
            if (prev >= 0 && nums[i] < comm) {
                prev = -1;
                len++;
            } else if (prev <= 0 && nums[i] > comm) {
                prev = 1;
                len++;
            }
            comm = nums[i];
        }
        return len;
    }
}
