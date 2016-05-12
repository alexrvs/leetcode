class Solution {
public:
    int integerBreak(int n) {
        vector<int> res;
        res.push_back(1);
        res.push_back(1);
        for (int i = 2; i <= n; i++) {
            int max = 1;
            for (int l = 1; l <= i / 2; l++) {
                int r = i - l;
                int a = l > res[l] ? l : res[l];
                int b = r > res[r] ? r : res[r];
                if (a * b > max) max = a * b;
            }
            res.push_back(max);
        }
        return res[n];
    }
};
