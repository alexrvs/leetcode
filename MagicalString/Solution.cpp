class Solution {
public:
    int magicalString(int n) {
        if (n == 0) return 0;
        if (n < 4) return 1;
        string magicStr = "122";
        int i = 2;
        int l = 3;
        while (l < n) {
            if ('2' == magicStr[i]) {
                if ('1' == magicStr[l - 1]) {
                    magicStr += "22";
                } else {
                    magicStr += "11";
                }
                l += 2;
            } else {
                if ('1' == magicStr[l - 1]) {
                    magicStr += "2";
                } else {
                    magicStr += "1";
                }
                l++;
            }
            i++;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ('1' == magicStr[i]) cnt++;
        }
        return cnt;
    }
};