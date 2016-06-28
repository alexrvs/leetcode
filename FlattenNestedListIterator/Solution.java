/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    private Iterator<NestedInteger> it;
    private NestedIterator nit;
    private Integer cur;

    public NestedIterator(List<NestedInteger> nestedList) {
        this.it = nestedList.iterator();
        nit = null;
    }

    @Override
    public Integer next() {
        if(!hasNext()) {
            throw new java.util.NoSuchElementException();
        }

        Integer result = cur;
        cur = null;
        return result;
    }

    @Override
    public boolean hasNext() {
        if (cur != null) return true;
        if (nit != null && nit.hasNext()) {
            cur = nit.next();
            return true;
        }
        while (it != null && it.hasNext()) {
            NestedInteger ni = it.next();
            if (ni.isInteger()) {
                cur = ni.getInteger();
                break;
            } else {
                nit = new NestedIterator(ni.getList());
                if (nit.hasNext()) {
                    cur = nit.next();
                    break;
                }
            }
        }
        if (cur != null) return true;
        return false;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
