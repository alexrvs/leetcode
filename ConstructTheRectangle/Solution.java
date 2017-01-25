public class Solution {
    public int[] constructRectangle(int area) {
        int[] res = new int[2];
        for (int i = area; i > 0; i--) {
            if (area % i == 0) {
                int w = i;
                int l = area / i;
                if (w <= l) {
                    res[0] = l;
                    res[1] = w;
                    break;
                }
            }
        }
        return res;
    }
}