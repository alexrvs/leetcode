class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n = nums.size();
            if (n < 1) return 0;
            vector<int> cnts(n, 1);
            int max = 1;
            for (int i = 1; i < n; i++) {
                int myMax = 0;
                for(int j = i - 1; j >= 0; j--) {
                    if (nums[j] < nums[i]) {
                        cnts[i] = cnts[j] + 1 > myMax ? cnts[j] + 1 : myMax;
                        if (max < cnts[i]) max = cnts[i];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                cout << cnts[i] << " ";
            }
            cout << endl;
            return max;
        }
};
