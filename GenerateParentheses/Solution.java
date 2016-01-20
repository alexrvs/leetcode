public class Solution {
    private void helper(List<String> res, String str, int a, int b) {
        if (a == 0 && b == 0) {
            res.add(str);
        } else if (a == 0) {
            helper(res, str + ")", a, b - 1);
        } else {
            helper(res, str + "(", a - 1, b);
            if (a < b) {
                helper(res, str + ")", a, b - 1);
            }
        }
        return;
    }

    public List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<String>();
        String str = "";
        helper(res, str, n, n);
        return res;
    }
}
