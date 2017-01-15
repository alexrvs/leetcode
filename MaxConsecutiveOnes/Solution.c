int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int cnt = 0;
    int max = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0) {
            cnt = 0;
        } else {
            cnt++;
            if (max < cnt) {
                max = cnt;
            }
        }
    }
    return max;
}