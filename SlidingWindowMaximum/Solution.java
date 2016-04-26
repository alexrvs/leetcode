public class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int nl = nums.length;
        if (nl == 0) {
            return new int[0];
        }
        int rl = nl - k + 1;
        int[] res = new int[rl];
        int r = 0;
        int[] can = new int[k];
        int first = 0;
        int last = -1;
        int size = 0;
        for (int i = 0; i < nl; i++) {
            if (size != 0 && can[first] < i - k + 1) {
                first = (first + 1) % k;
                size--;
            }
            while (size != 0 && nums[can[last]] < nums[i]) {
                last = (last + k - 1) % k;
                size--;
            }
            last = (last + 1) % k;
            can[last] = i;
            size++;
            if (i >= k - 1) {
                res[r++] = nums[can[first]];
            }
        }
        return res;
    }
}
