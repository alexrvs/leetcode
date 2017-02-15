class Solution {
public:
    string convertToBase7(int num) {
        vector<int> res;
        stringstream resStr;
        if (num < 0) {
            resStr << "-";
            num = -num;
        }
        do {
            res.push_back(num % 7);
            num = num / 7;
        } while(num != 0);
        int size = res.size();
        for (int i = size - 1; i >= 0; i--) {
            resStr << res[i];
        }
        return resStr.str();
    }
};