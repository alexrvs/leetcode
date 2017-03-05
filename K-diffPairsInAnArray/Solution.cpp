class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> idx;
        int size = nums.size();
        int cnt = 0;
        for (int i = size - 1; i >= 0; i--) {
            if (k == 0) {
                if (idx.find(nums[i]) == idx.end()) {
                    idx[nums[i]] = i;
                } else if (idx[nums[i]] != -1) {
                    cnt++;
                    idx[nums[i]] = -1;
                }
            } else {
                if (idx.find(nums[i]) == idx.end()) {
                    if (idx.find(nums[i] - k) != idx.end()) {
                        cnt++;
                    }
                    if (idx.find(nums[i] + k) != idx.end()) {
                        cnt++;
                    }
                    idx[nums[i]] = i;
                }
            }
        }
        return cnt;
    }
};