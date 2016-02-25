class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> idx(k, 0);
        vector<int> un;
        un.push_back(1);
        for (int i = 0; i < n; i++) {
            int minNum = -1;
            for (int j = 0; j < k; j++) {
                int num = primes[j] * un[idx[j]];
                if (minNum == -1 || num < minNum) {
                    minNum = num;
                }
            }
            un.push_back(minNum);
            for (int j = 0; j < k; j++) {
                int num = primes[j] * un[idx[j]];
                if (minNum == num) {
                    idx[j]++;
                }
            }
        }
        return un[n - 1];
    }
};
