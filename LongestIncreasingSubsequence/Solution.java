public class Solution {
    private int search(int[] seq, int l, int r, int target) {
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (seq[m] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if (n == 0) return 0;
        int[] seq = new int[n];
        int seqLen = 0;
        for (int i = 0; i < n; i++) {
            int pos = search(seq, 0, seqLen, nums[i]);
            seq[pos] = nums[i];
            if (pos == seqLen) seqLen++;
        }
        return seqLen;
    }
}
