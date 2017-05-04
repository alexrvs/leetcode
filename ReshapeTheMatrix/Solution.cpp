class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res;
        int nums_r = nums.size();
        if (nums_r == 0) {
            return res;
        }
        int nums_c = nums[0].size();
        if (nums_r * nums_c < r * c) {
            return nums;
        }
        int idx = 0;
        for (int i = 0; i < r; i++) {
            res.push_back(vector<int>(c, 0));
            for (int j = 0; j < c; j++) {
                idx = c * i + j;
                res[i][j] = nums[idx / nums_c][idx % nums_c];
            }
        }
        return res;
    }
};