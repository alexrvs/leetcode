class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if (n == 0) {
            res.push_back(0);
            return res;
        }
        int num = 1;
        for (int i = 1; i < n; i++) {
            num <<= 1;
            num |= 0x01;
        }
        int mask = 1;
        int idx = 0;
        for (int i = 0; i <= num; i++) {
            if (i < 2) res.push_back(i);
            else {
                if (i == mask << 1) {
                    mask <<= 1;
                    idx = res.size() - 1;
                }
                res.push_back( mask ^ res[idx--]);
            }
        }
        return res;
    }
};
