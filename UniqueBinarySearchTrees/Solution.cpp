class Solution {
public:
    int numTrees(int n) {
        vector<int> nums(n + 1);
        nums[0] = 1;
        for (int i = 1; i <= n; i++) {
            nums[i] = 0;
            for (int j = 1; j <= i; j++) {
                nums[i] += nums[j - 1] * nums[i - j];
            }
        }
        return nums[n];
    }
};
