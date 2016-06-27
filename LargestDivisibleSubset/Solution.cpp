class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> steps(size, 0);
        vector<int> idx(size, 0);
        int maxIdx = 0;
        int maxStep = 0;
        for (int i = 0; i < size; i++) {
            steps[i] = 1;
            idx[i] = i;
            if (steps[i] > maxStep) {
                maxStep = steps[i];
                maxIdx = i;
            }
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0) {
                    steps[i] = steps[j] + 1;
                    idx[i] = j;
                    if (steps[i] > maxStep) {
                        maxStep = steps[i];
                        maxIdx = i;
                    }
                    break;
                }
            }
        }
        vector<int> res(maxStep, 0);
        while (maxStep-- != 0) {
            res[maxStep] = nums[maxIdx];
            maxIdx = idx[maxIdx];
        }
        return res;
    }
};
