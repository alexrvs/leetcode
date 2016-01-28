class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size < 1) return 0;
        int sum = nums[0];
        int max = nums[0];
        for (int i = 1; i < size; i++) {
            sum += nums[i];
            if (sum < nums[i]) {
                sum = nums[i];
            }
            if (sum > max) {
                max = sum;
            }
        }
        return max;
    }
};
