int maxRotateFunction(int* A, int ASize) {
    int total = 0;
    int sum = 0;
    int max = 0;
    for (int i = 0; i < ASize; i++) {
        total += A[i];
        sum += i * A[i];
    }
    max = sum;
    for (int i = 1; i < ASize; i++) {
        sum += total;
        sum -= ASize * A[ASize - i];
        max = max > sum ? max : sum;
    }
    return max;
}
