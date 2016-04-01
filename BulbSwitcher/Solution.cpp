class Solution {
public:
    int bulbSwitch(int n) {
        if (n < 2) return n;
        int i = 0;
        while (i * i <= n) i++;
        return i - 1;
    }
};
