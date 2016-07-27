int nthUglyNumber(int n) {
    int* ugly_nums = (int*) malloc(n * sizeof(int));
    int num2, num3, num5, i2, i3, i5, min_num;
    i2 = i3 = i5 = 0;
    ugly_nums[0] = 1;
    int cnt = 1;
    while (cnt < n) {
        num2 = ugly_nums[i2]*2;
        num3 = ugly_nums[i3]*3;
        num5 = ugly_nums[i5]*5;
        min_num = num2 < num3 ? num2 : num3;
        min_num = min_num < num5 ? min_num : num5;
        ugly_nums[cnt++] = min_num;
        if (num2 == min_num) {
            i2++;
        }
        if (num3 == min_num) {
            i3++;
        }
        if (num5 == min_num) {
            i5++;
        }
    }
    min_num = ugly_nums[n - 1];
    free(ugly_nums);
    return min_num;
}

