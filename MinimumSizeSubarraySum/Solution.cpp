class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        int min = 0;
        int start = 0;
        int end = 0;
        int len = 0;
        int sum = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] >= s) return 1;
            sum += nums[i];
            if (sum >= s) {
                end = i;
                for (int j = start; j < i; j++) {
                    if (sum - nums[j] >= s) {
                        sum -= nums[j];
                        start = j + 1;
                    } else {
                        break;
                    }
                }
                len = (end - start) + 1;
                if (min == 0 || min > len) {
                    min = len;
                }
            }
        }
        return min;
    }
};
