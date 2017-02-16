public class Solution {
    public String convertToBase7(int num) {
        List<Integer> res = new ArrayList<Integer>();
        String resStr = "";
        if (num < 0) {
            resStr += "-";
            num = -num;
        }
        do {
            res.add(num % 7);
            num = num / 7;
        } while(num != 0);
        int size = res.size();
        for (int i = size - 1; i >= 0; i--) {
            resStr += res.get(i);
        }
        return resStr.toString();
    }
}