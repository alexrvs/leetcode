class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> res;
        for (int i = 0; i < size; i++) {
            int idx = (nums[i] >= 0 ? nums[i] : -nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(idx + 1);
            nums[idx] = -nums[idx];
        }
        return res;
    }
};