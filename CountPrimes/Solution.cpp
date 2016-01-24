class Solution {
public:
    int countPrimes(int n) {
        bool * isPrime = new bool[n];
        for (int i = 2; i < n; i++) isPrime[i] = true;
        int l = 0;
        while (l * l < n) l++;
        for (int i = 2; i <= l; i++) {
            if (! isPrime[i]) continue;
            for (int j = i * i; j < n; j +=i) {
                isPrime[j] = false;
            }
        }
        int cnt = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                cnt++;
            }
        }
        return cnt;
    }
};
