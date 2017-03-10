public class Solution {
    
    private int cal(int res, char op, int opNum) {
        if ('+' == op) {
            res += opNum;
        } else if ('-' == op) {
            res -= opNum;
        } else if ('*' == op) {
            res *= opNum;
        } else if ('/' == op) {
            res /= opNum;
        }
        return res;
    }
    
    public int calculate(String s) {
        int res = 0;
        char op = '+';
        int opNum = 0;
        int idx = 0;
        Stack<Integer> resStack = new Stack<Integer>();
        Stack<Character> opStack = new Stack<Character>();
        while (idx < s.length()) {
            if (s.charAt(idx) != ' ') {
                if ('0' <= s.charAt(idx) && '9' >= s.charAt(idx)) {
                    opNum = opNum * 10 + (int) s.charAt(idx) - '0';
                } else if ('*' == s.charAt(idx) || '/' == s.charAt(idx)) {
                    if ('+' == op || '-' == op) {
                        resStack.push(res);
                        opStack.push(op);
                        res = opNum;
                    } else {
                        res = cal(res, op, opNum);
                    }
                    opNum = 0;
                    op = s.charAt(idx);
                } else if ('+' == s.charAt(idx) || '-' == s.charAt(idx)){
                    res = cal(res, op, opNum);
                    if ('*' == op || '/' == op) {
                        opNum = res;
                        op = opStack.pop();
                        res = resStack.pop();
                        res = cal(res, op, opNum);
                    }
                    opNum = 0;
                    op = s.charAt(idx);
                }
            }
            idx++;
        }
        res = cal(res, op, opNum);
        if ('*' == op || '/' == op) {
            opNum = res;
            op = opStack.pop();
            res = resStack.pop();
            res = cal(res, op, opNum);
        }
        return res;
    }
}