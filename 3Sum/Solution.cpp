class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        int size = nums.size();
        if (size < 3) return res;
        sort(nums.begin(), nums.end());
        int prev = 0;
        for (int i = 0; i < size - 2; ) {
            for (int j = i + 1, k = size - 1; j < k; ) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> r;
                    r.push_back(nums[i]);
                    r.push_back(nums[j]);
                    r.push_back(nums[k]);
                    res.push_back(r);
                    prev = nums[j];
                    while (nums[j] == prev && j < k) j++;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    prev = nums[j];
                    while (nums[j] == prev && j < k) j++;
                } else {
                    prev = nums[k];
                    while (nums[k] == prev && j < k) k--;
                }
            }
            prev = nums[i];
            while (nums[i] == prev && i < size) i++;
        }
        return res;
    }
};
