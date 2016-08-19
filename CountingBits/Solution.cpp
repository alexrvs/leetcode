class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        int n = 1;
        for (int i = 1; i <= num; i++) {
            if (i - n >= n) n <<= 1;
            res.push_back(1 + res[i - n]);
        }
        return res;
    }
};
