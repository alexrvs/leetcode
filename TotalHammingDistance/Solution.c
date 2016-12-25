int totalHammingDistance(int* nums, int numsSize) {
     int cnt[32][2];
     for (int i = 0;i < 32; i++) {
         cnt[i][0] = 0;
         cnt[i][1] = 0;
     }
     int mask = 0x1;
     for (int i = 0; i < numsSize; i++) {
         int tmp = nums[i];
         for (int j = 0; j < 32; j++) {
             if ((tmp & mask) == 0) {
                 cnt[j][0]++;
             } else {
                 cnt[j][1]++;
             }
             tmp >>= 1;
         }
     }
     int res = 0;
     for (int i = 0; i < 32; i++) {
         res += cnt[i][0] * cnt[i][1];
     }
     return res;
}