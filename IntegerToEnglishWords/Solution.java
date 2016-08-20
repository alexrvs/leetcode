public class Solution {
    String[] ones = { "Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" };
    String[] elevens = { "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    String[] tens = { "Start", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
    private String numToString(int num) {
        int h = num / 100;
        num %= 100;
        int t = num / 10;
        num %= 10;
        int o = num;
        String res = "";
        if (h > 0) {
            res += ones[h] + " Hundred";
        }
        if (t > 0) {
            if (res != "") res += " ";
            if (t == 1 && o > 0) {
                res += elevens[o];
                return res;
            } else {
                res += tens[t];
            }
        }
        if (o > 0) {
            if (res != "") res += " ";
            res += ones[o];
        }
        return res;
    }

    public String numberToWords(int num) {
        if (num == 0) return "Zero";
        int[] nums = new int[4];
        nums[0] = num / 1000000000;
        num = num % 1000000000;
        nums[1] = num / 1000000;
        num = num % 1000000;
        nums[2] = num / 1000;
        num = num % 1000;
        nums[3] = num;
        String res = "";
        if (nums[0] != 0) {
            res += numToString(nums[0]);
            res += " Billion";
        }
        if (nums[1] != 0) {
            if (res != "") res += " ";
            res += numToString(nums[1]);
            res += " Million";
        }
        if (nums[2] != 0) {
            if (res != "") res += " ";
            res += numToString(nums[2]);
            res += " Thousand";
        }
        if (nums[3] != 0) {
            if (res != "") res += " ";
            res += numToString(nums[3]);
        }
        return res;
    }
}
