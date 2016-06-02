class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res  = nums[0];
        int tmax = nums[0];
        int tmin = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int prod1 = tmax * nums[i];
            int prod2 = tmin * nums[i];
            tmax = max(max(prod1, prod2), nums[i]);
            tmin = min(min(prod1, prod2), nums[i]);
            res = max(res, tmax);
        }
        return res;
    }
};
