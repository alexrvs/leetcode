class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        int max = 0;
        int sum = 0;
        int pred = 0;
        for (int i = 0; i < size; i++) {
            max = nums[i];
            pred = i-1;
            int j = i > 4 ? i-4 : 0;
            for (; j >=0 && j < pred; j++) {
                sum = nums[i]+nums[j];
                if (sum > max) {
                    max = sum;
                }
            }
            nums[i] = max;
        }
        return nums[size-1] > nums[size-2] ? nums[size-1] : nums[size-2];

    }
};
