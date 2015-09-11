public class Solution {
        public List<Integer> diffWaysToCompute(String input) {
        List<Integer> res = new ArrayList<Integer>();
        try {
            int num = Integer.parseInt(input);
            res.add(num);
            return res;
        } catch (NumberFormatException e) {

        }
        List<Integer> left;
        List<Integer> right;
        for (int i = 0; i < input.length(); i++) {
            char op = input.charAt(i);
            if ('+' == op || '-' == op || '*' == op) {
                left = diffWaysToCompute(input.substring(0, i));
                right = diffWaysToCompute(input.substring(i+1));
                for (Integer j : left) {
                    for (Integer k : right) {
                        if ('+' == op) {
                            res.add(j + k);
                        } else if ('-' == op) {
                            res.add(j - k);
                        } else if ('*' == op) {
                            res.add(j * k);
                        }
                    }
                }
            }
        }
        return res;
    }
}
