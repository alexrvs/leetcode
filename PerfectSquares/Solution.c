int numSquares(int n) {
    int least = 0;
    int num = 0;
    int* nums = (int*) malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) {
        least = i;
        for (int x = 1; x * x <= i; x++) {
            num = 1 + nums[ i - x * x ];
            if (least > num) {
                least = num;
            }
        }
        nums[i] = least;
    }
    num = nums[n];
    free(nums);
    return num;
}
