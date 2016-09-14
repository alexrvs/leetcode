public class Solution {
    public int maxRotateFunction(int[] A) {
        int total = 0;
        int sum = 0;
        int max = 0;
        for (int i = 0; i < A.length; i++) {
            total += A[i];
            sum += i * A[i];
        }
        max = sum;
        for (int i = 1; i < A.length; i++) {
            sum += total;
            sum -= A.length * A[A.length - i];
            max = max > sum ? max : sum;
        }
        return max;
    }
}
