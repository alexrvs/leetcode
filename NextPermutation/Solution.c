void reverse(int* nums, int i, int j) {
    int temp;
    while (i < j) {
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
        j--;
    }
    return;
}

void nextPermutation(int* nums, int numsSize) {
    int i, j;
    for(i = numsSize - 2; i >= 0; i--) {
        if(nums[i] < nums[i + 1]) {
            for(j = numsSize - 1; j > i - 1; j--) {
                if(nums[i] < nums[j]) {
                    break;
                }
            }
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            reverse(nums, i + 1, numsSize - 1);
            return;
        }
    }
    reverse(nums, 0, numsSize - 1);
    return;
}