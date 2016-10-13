class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> cnt(target + 1, 0);
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] > i) break;
                else if (nums[j] == i) {
                    cnt[i] += 1;
                } else {
                    cnt[i] += cnt[i - nums[j]];
                }
            }
        }
        return cnt[target];
    }
};