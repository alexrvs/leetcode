void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp;
    return;
}

int helper(int* nums, int N) {
    if (N <= 1) return 1;
    int res = 0;
    for (int i = 0; i < N; i++) {
        if (nums[i] % N == 0 || N % nums[i] == 0) {
            swap(nums, i, N - 1);
            res += helper(nums, N - 1);
            swap(nums, i, N - 1);
        }
    }
    return res;
}

int countArrangement(int N) {
    if (N == 0) return 0;
    int* nums = (int*) malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        nums[i] = i + 1;
    }
    return helper(nums, N);
}