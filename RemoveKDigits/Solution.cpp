class Solution {
public:
    string removeKdigits(string num, int k) {
        int size = num.size();
        string res;
        if (k >= size) {
            res = "0";
            return res;
        }
        vector<bool> removed(size, false);
        for (int i = 1; i < size && k > 0; i++) {
            for (int j = i - 1; j >= 0 && k > 0; j--) {
                if (num[j] <= num[i]) break;
                if (removed[j] == false) {
                    k--;
                    removed[j] = true;
                }
            }
        }
        int last = size - 1;
        while (k > 0 && last >= 0) {
            if (removed[last] == false) {
                k--;
                removed[last] = true;
            }
            last--;
        }
        for (int i = 0; i < size; i++) {
            if (removed[i] == false) {
                if (num[i] == '0' && res.size() == 0) continue;
                else res += num[i];
            }
        }
        if (res.size() == 0) {
            res = "0";
        }
        return res;
    }
};
