public class Solution {
    public int findMaximumXOR(int[] nums) {
        int res = 0;
        int mask = 0;
        int size = nums.length;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            Set<Integer> numHighBits = new HashSet<Integer>();
            for (int j = 0; j < size; j++) {
                numHighBits.add(nums[j] & mask);
            }
            int curMax = res | (1 << i);
            for (int highBits : numHighBits) {
                if (numHighBits.contains(curMax ^ highBits)) {
                    res = curMax;
                    break;
                }
            }
        }
        return res;
    }
}