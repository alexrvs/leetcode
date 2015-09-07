class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int mi = m+n-1;
        int ai = m-1;
        int bi = n-1;
        while (ai >= 0 && bi>=0) {
            if (A[ai] > B[bi]) {
                A[mi] = A[ai];
                ai--;
            } else {
                A[mi] = B[bi];
                bi--;
            }
            mi--;
        }
        if (ai < 0) {
            while (bi >= 0) {
                A[mi] = B[bi];
                mi--;
                bi--;
            }
        }
        return;
    }
};
