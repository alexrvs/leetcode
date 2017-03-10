public class Solution {
    
    private int cal(int res, char op, int opNum) {
        if ('+' == op) {
            res += opNum;
        } else if ('-' == op) {
            res -= opNum;
        }
        return res;
    }
    
    public int calculate(String s) {
        int res = 0;
        char op = '+';
        int opNum = 0;
        int idx = 0;
        int stackTail = -1;
        Stack<Integer> resStack = new Stack<Integer>();
        Stack<Character> opStack = new Stack<Character>();
        while (idx < s.length()) {
            if (s.charAt(idx) != ' ') {
                if ('(' == s.charAt(idx)) {
                    resStack.push(res);
                    opStack.push(op);
                    res = 0;
                    opNum = 0;
                    op = '+';
                } else if (')' == s.charAt(idx)) {
                    res = cal(res, op, opNum);
                    opNum = res;
                    op = opStack.pop();
                    res = resStack.pop();
                } else if ('0' <= s.charAt(idx) && '9' >= s.charAt(idx)) {
                    opNum = opNum * 10 + (int) s.charAt(idx) - '0';
                } else if ('+' == s.charAt(idx) || '-' == s.charAt(idx)){
                    res = cal(res, op, opNum);
                    opNum = 0;
                    op = s.charAt(idx);
                }
            }
            idx++;
        }
        res = cal(res, op, opNum);
        return res;
    }
    
}