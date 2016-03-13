class Solution {
private:
    int helper(vector<int> nums, int start, int end) {
        int max = 0;
        for (int i = start; i <= end; i++) {
            if (i - 3 >= start) {
                if (max < nums[i] + nums[i - 3]) max = nums[i] + nums[i - 3];
            }
            if (i - 2 >= start) {
                if (max < nums[i] + nums[i - 2]) max = nums[i] + nums[i - 2];
            }
            if (max < nums[i]) max = nums[i];
            nums[i] = max;
        }
        return max;
    }

public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        int m1 = helper(nums, 0, size - 2);
        int m2 = helper(nums, 1, size - 1);
        return (m1 > m2 ? m1 : m2);
    }
};
