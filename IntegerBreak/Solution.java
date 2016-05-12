public class Solution {
    public int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        switch (n % 3) {
            case 0 : return (int)Math.pow(3, n / 3);
            case 1 : return (int)Math.pow(3, (n / 3) - 1) * 4;
            case 2 : return (int)Math.pow(3, n / 3) * 2;
        }
        return 0;
    }
}
