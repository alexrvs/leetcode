class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int total = 0;
        int sum = 0;
        int max = 0;
        int size = A.size();
        for (int i = 0; i < size; i++) {
            total += A[i];
            sum += i * A[i];
        }
        max = sum;
        for (int i = 1; i < size; i++) {
            sum += total;
            sum -= size * A[size - i];
            max = max > sum ? max : sum;
        }
        return max;
    }
};
