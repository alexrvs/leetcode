public class Solution {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<Integer>();
        if (n == 0) {
            res.add(0);
            return res;
        }
        int num = 1;
        for (int i = 1; i < n; i++) {
            num <<= 1;
            num |= 0x01;
        }
        int mask = 1;
        int idx = 0;
        for (int i = 0; i <= num; i++) {
            if (i < 2) res.add(i);
            else {
                if (i == mask << 1) {
                    mask <<= 1;
                    idx = res.size() - 1;
                }
                res.add( mask ^ res.get(idx--));
            }
        }
        return res;
    }
}
