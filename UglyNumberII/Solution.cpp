class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly_nums;
        int num2, num3, num5, i2, i3, i5, min_num;
        i2 = i3 = i5 = 0;
        ugly_nums.push_back(1);
        while (ugly_nums.size() < n) {
            num2 = ugly_nums[i2]*2;
            num3 = ugly_nums[i3]*3;
            num5 = ugly_nums[i5]*5;
            min_num = min(num2, min(num3, num5));
            ugly_nums.push_back(min_num);
            if (num2 == min_num) i2++;
            if (num3 == min_num) i3++;
            if (num5 == min_num) i5++;
        }
        return ugly_nums[n-1];
    }
};
