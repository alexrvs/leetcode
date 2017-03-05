class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int size = nums.size();
        if (k < 0) k = -k;
        vector<int> sums(size + 1, 0);
        for (int i = 0; i < size; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
        unordered_map<int, int> idx;
        for (int i = 0; i <= size; i++) {
            if (k == 0) {
                if (sums[i] == 0 && i > 1) {
                    return true;
                }
            } else {
                int rem = sums[i] % k;
                if (idx.find(rem) == idx.end()) {
                    idx[rem] = i;
                }
                else {
                    if (i - idx[rem] > 1) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};