class Solution {
private:
    void permuteUnique(string& res, vector<int> &nums, vector<int>& used, int n, int k) {
        if (k == 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (used[i] != 1) res += '0' + nums[i];
            }
            return;
        }
        int size = nums.size();
        int temp = 1;
        int i = 1;
        while (i < n) {
            temp *= i;
            i++;
        }
        int idx = k / temp;
        for (int i = 0; i < size; i++) {
            if (used[i] != 1 && idx-- == 0) {
                res += '0' + nums[i];
                used[i] = 1;
            }
        }
        k %= temp;
        permuteUnique(res, nums, used, n - 1, k);
        return;
    }

public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        for (int i = 0; i < n; i++) {
            nums.push_back(i + 1);
        }
        vector<int> used(n, 0);
        string res = "";
        permuteUnique(res, nums, used, n, k - 1);
        return res;
    }
};
