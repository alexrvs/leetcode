class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        sort(nums.begin(), nums.end());
        int median = nums[size / 2];
        int steps = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] > median) steps += nums[i] - median;
            else steps += median - nums[i];
        }
        return steps;
    }
};