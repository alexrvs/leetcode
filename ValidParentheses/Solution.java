public class Solution {
    public boolean isValid(String s) {
        Stack<Character> left = new Stack<Character>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            switch(c) {
                case '(':
                case '[':
                case '{':
                    left.push(c);
                    break;
                case ')':
                    if (left.size() > 0 && left.peek() == '(') {
                        left.pop();
                    } else return false;
                    break;
                case ']':
                    if (left.size() > 0 && left.peek() == '[') {
                        left.pop();
                    } else return false;
                    break;
                case '}':
                    if (left.size() > 0 && left.peek() == '{') {
                        left.pop();
                    } else return false;
                    break;
            }
        }
        if (left.size() > 0) return false;
        return true;
    }
}
