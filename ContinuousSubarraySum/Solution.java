public class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        int size = nums.length;
        if (k < 0) k = -k;
        int[] sums = new int[size + 1];
        for (int i = 0; i < size; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        Map<Integer, Integer> idx = new HashMap<Integer, Integer>();
        for (int i = 0; i <= size; i++) {
            if (k == 0) {
                if (sums[i] == 0 && i > 1) {
                    return true;
                }
            } else {
                int rem = sums[i] % k;
                if (!idx.containsKey(rem)) {
                    idx.put(rem, i);
                }
                else {
                    if (i - idx.get(rem) > 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}