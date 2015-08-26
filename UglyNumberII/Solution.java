public class Solution {
    public int nthUglyNumber(int n) {
        List<Integer> ugly_nums = new ArrayList<Integer>();
        int num2, num3, num5, i2, i3, i5, min_num;
        i2 = i3 = i5 = 0;
        ugly_nums.add(1);
        while (ugly_nums.size() < n) {
            num2 = ugly_nums.get(i2)*2;
            num3 = ugly_nums.get(i3)*3;
            num5 = ugly_nums.get(i5)*5;
            min_num = Math.min(num2, Math.min(num3, num5));
            ugly_nums.add(min_num);
            if (num2 == min_num) i2++;
            if (num3 == min_num) i3++;
            if (num5 == min_num) i5++;
        }
        return ugly_nums.get(n-1);
    }
}
