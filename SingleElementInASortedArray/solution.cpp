class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0;
        int r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (m - 1 >= 0 && nums[m - 1] == nums[m]) {
                if ((r - m) % 2 == 0) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (m + 1 < nums.size() && nums[m + 1] == nums[m]) {
                if ((m - l) % 2 == 1) {
                    r = m;
                } else {
                    l = m + 2;
                }
            } else {
                return nums[m];
            }
        }
        return nums[l];
    }
};