public class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int size = nums.length;
        int[] res = new int[size];
        for (int i = 0; i < size; i++) {
            res[i] = -1;
            for (int j = 1; j < size; j++) {
                int idx = (i + j) % size;
                if (nums[i] < nums[idx]) {
                    res[i] = nums[idx];
                    break;
                }
            }
        }
        return res;
    }
}