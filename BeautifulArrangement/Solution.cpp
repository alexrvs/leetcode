class Solution {
private:
    int helper(vector<int>& nums, int N) {
        if (N <= 1) return 1;
        int res = 0;
        for (int i = 0; i < N; i++) {
            if (nums[i] % N == 0 || N % nums[i] == 0) {
                swap(nums[i], nums[N - 1]);
                res += helper(nums, N - 1);
                swap(nums[i], nums[N - 1]);
            }
        }
        return res;
    }
    
public:
    int countArrangement(int N) {
        vector<int> nums;
        for (int i = 1; i <= N; i++) {
            nums.push_back(i);
        }
        return helper(nums, N);
    }
};