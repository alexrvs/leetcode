class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;
        int a[2];
        int max = nums[0];
        for (int i = 1; i < n; i++) {
            if (max < nums[i]) max = nums[i];
        }
        a[0] = max;
        a[1] = max;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= a[0]) {
                a[0] = nums[i];
            } else if (nums[i] < a[1]) {
                a[1] = nums[i];
            }
            if (nums[i] > a[0] && nums[i] > a[1]) return true;
        }
        return false;
    }
};
