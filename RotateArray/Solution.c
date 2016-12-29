void reverse(int* nums, int l, int r) {
    int tmp = 0;
    while (l < r) {
        tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        l++;
        r--;
    }
    return;
}

void rotate(int* nums, int numsSize, int k) {
    int l = 0;
    int r = numsSize - 1;
    k = k % numsSize;
    reverse(nums, l, r);
    l = 0;
    r = k - 1;
    reverse(nums, l, r);
    l = k;
    r = numsSize - 1;
    reverse(nums, l, r);
    return;
}