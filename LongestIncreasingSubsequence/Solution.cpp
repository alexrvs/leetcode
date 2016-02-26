class Solution {
private:
    int search(vector<int>& seq, int l, int r, int target) {
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (seq[i] < target) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l - 1;
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 1) return 0;
        vector<int> seq(n, 0);
        int seqLen = 0;
        for (int i = 0; i < n; i++) {
            int pos = search(seq, 0, seqLen, nums[i]) + 1;
            seq[pos] = nums[i];
            if (pos == seqLen) {
                seqLen = pos + 1;
            }
        }
        return seqLen;
    }
};
