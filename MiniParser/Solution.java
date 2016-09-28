/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *     // Constructor initializes an empty nested list.
 *     public NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     public NestedInteger(int value);
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // Set this NestedInteger to hold a single integer.
 *     public void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     public void add(NestedInteger ni);
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class Solution {

    private List<NestedInteger> elems = new ArrayList<NestedInteger>();

    private NestedInteger helper(String s, int start, int end) {
        NestedInteger ni = new NestedInteger();
        int nestedStart = -1;
        int n = 0;
        int num = 0;
        if (s.charAt(start) != '[') {
            boolean neg = false;
            for (int i = start; i <= end; i++) {
                if (s.charAt(i) == '-') {
                    neg = true;
                } else {
                    num = 10 * num + (s.charAt(i) - '0');
                }
            }
            if (neg == true) num *= -1;
            ni.setInteger(num);
        } else {
            start++;
            end--;
            int lastStart = start;
            for (int i = start ; i <= end; i++) {
                if (s.charAt(i) == '[') {
                    n++;
                    if (nestedStart == -1) nestedStart = i;
                } else if (s.charAt(i) == ']') {
                    n--;
                } else if (s.charAt(i) == ',' && n == 0) {
                    ni.add(helper(s, lastStart, i - 1));
                    lastStart = i + 1;
                }
                if (i == end) ni.add(helper(s, lastStart, end));
            }
        }
        return ni;
    }

    public NestedInteger deserialize(String s) {
        return helper(s, 0, s.length() - 1);
    }
}
