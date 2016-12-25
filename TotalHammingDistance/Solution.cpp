class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<vector<int> > cnt(32, vector<int>(2, 0));
        int size = nums.size();
        int mask = 0x1;
        for (int i = 0; i < size; i++) {
            int tmp = nums[i];
            for (int j = 0; j < 32; j++) {
                if ((tmp & mask) == 0) {
                    cnt[j][0]++;
                } else {
                    cnt[j][1]++;
                }
                tmp >>= 1;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res += cnt[i][0] * cnt[i][1];
        }
        return res;
    }
};