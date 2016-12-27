class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int min = nums[0];
        int max = nums[0];
        for (int i = 1; i < size; i++) {
            if (nums[i] < min) min = nums[i];
            if (nums[i] > max) max = nums[i];
        }
        int diff = max - min;
        int gap = (max - min) / (size - 1);
        if ((diff % (size - 1)) != 0) gap++;
        vector<int> minBuckets(size - 1, max);
        vector<int> maxBuckets(size - 1, min);
        for (int i = 0; i < size; i++) {
            if (nums[i] == max || nums[i] == min) {
                continue;
            }
            int idx = (nums[i] - min) / gap;
            if (minBuckets[idx] > nums[i]) minBuckets[idx] = nums[i];
            if (maxBuckets[idx] < nums[i]) maxBuckets[idx] = nums[i];
        }
        int prev = min;
        int maxGap = 0;
        gap = 0;
        for (int i = 0; i < size - 1; i++) {
            if (minBuckets[i] == max || maxBuckets[i] == min) {
                continue;
            }
            gap = minBuckets[i] - prev;
            if (maxGap < gap) maxGap = gap;
            prev = maxBuckets[i];
        }
        gap = max - prev;
        if (maxGap < gap) maxGap = gap;
        return maxGap;
    }
};