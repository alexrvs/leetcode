class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        int l = 0;
        int r = size;
        int m = 0;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < target) { 
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
};
