class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> nums(n + 1, 0);
        nums[0] = 1;
        if (n >= 1) nums[1] = 9;
        for (int i = 2; i <= n; i++) {
            nums[i] = nums[i - 1] * max(0, 11 - i);
        }
        for (int i = 1; i <= n; i++) {
            nums[i] += nums[i - 1];
        }
        return nums[n];
    }
};
