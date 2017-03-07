public class Solution {
    public int findPairs(int[] nums, int k) {
        if (k < 0) return 0;
        Map<Integer, Integer> idx = new HashMap<Integer, Integer>();
        int size = nums.length;
        int cnt = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (k == 0) {
                if (!idx.containsKey(nums[i])) {
                    idx.put(nums[i], i);
                } else if (!idx.get(nums[i]).equals(-1)) {
                    cnt++;
                    idx.put(nums[i], -1);
                }
            } else {
                if (!idx.containsKey(nums[i])) {
                    if (idx.containsKey(nums[i] - k)) {
                        cnt++;
                    }
                    if (idx.containsKey(nums[i] + k)) {
                        cnt++;
                    }
                    idx.put(nums[i], i);
                }
            }
        }
        return cnt;
    }
}