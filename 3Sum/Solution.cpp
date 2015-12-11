class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size - 2; ) {
            for (int j = i + 1, k = size - 1; j < k; ) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> r;
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    r.push_back(nums[k]);
                    res.push_back(r);
                    while (j < k && nums[++j] == nums[j - 1]);
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    while (j < k && nums[++j] == nums[j - 1]);
                } else {
                    while (j < k && nums[--k] == nums[k + 1]);
                }
            }
            while (i < size && nums[++i] == nums[i - 1]);
        }
        return res;
    }
};
