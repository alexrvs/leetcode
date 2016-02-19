class Solution {
public:
    int search(vector<int>& nums, int target) {
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
        r = l - 1;
        l %= size;
        while (l != r) {
            m = (l + ((r - l + size) % size) / 2) % size;
            if (nums[m] < target) {
                l = (m + 1) % size;
            } else {
                r = m;
            }
        }
        if (nums[l] == target) return l;
        return -1;
    }
};
