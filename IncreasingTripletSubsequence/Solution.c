bool increasingTriplet(int* nums, int numsSize) {
    int min1, min2;
    if (numsSize == 0) return false;
    min1 = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (min1 < nums[i]) min1 = nums[i];
    }
    min2 = min1;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= min1) {
            min1 = nums[i];
        } else if (nums[i] <= min2) {
            min2 = nums[i];
        } else return true;
    }
    return false;
}
