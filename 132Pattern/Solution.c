bool find132pattern(int* nums, int numsSize) {
    int* largers = (int*) malloc(numsSize * sizeof(int));
    int largersSize = 0;
    int s3 = INT_MIN;
    for (int i = numsSize - 1; i >= 0; i--) {
        if (nums[i] < s3) {
            return true;
        } else {
            while (0 != largersSize && largers[largersSize - 1] < nums[i]) {
                s3 = largers[largersSize - 1];
                largersSize--;
            }
        }
        largersSize++;
        largers[largersSize - 1] = nums[i];
    }
    return false;
}