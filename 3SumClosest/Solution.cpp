class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[size-1];
        int sum = 0;
        int minus = 0;
        int min = abs(closest - target);
        int j,k;
        for (int i = 0; i < size - 2; i++) {
            j = i + 1;
            k = size - 1;
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                minus = abs(sum - target);
                if (minus < min) {
                    closest = sum;
                    min = minus;
                }
                if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
                else
                    return sum;
            }
        }
        return closest;
    }
};
