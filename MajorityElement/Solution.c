int majorityElement(int* nums, int numsSize) {
    int major = nums[0];
    int count = 1;
    for (int i = 1; i < numsSize; i++) {
        if (count != 0) {
            if (major != nums[i]) {
                count--;
            } else {
                count++;
            }
        } else {
            major = nums[i];
            count = 1;
        }
    }
    return major;
}
