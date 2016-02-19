class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();
        int l = 0;
        int r = size;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] >= nums[0]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        if (l >= size) return nums[0];
        return nums[l];
    }
};
