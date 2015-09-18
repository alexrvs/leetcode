class Solution {
public:
    bool isHappy(int n) {
        int used[100];
        int sum = 0;
        int d = 0;
        for (int i = 0; i < 100; i++) {
            used[i] = 0;
        }
        while (n >= 100 || used[n] != 1) {
            if (n < 100) used[n] = 1;
            sum = 0;
            while (n > 0) {
                d = n % 10;
                sum += d * d;
                n /= 10;
            }
            cout << sum << endl;
            if (sum == 1) return true;
            n = sum;
        }
        return false;
    }
};
