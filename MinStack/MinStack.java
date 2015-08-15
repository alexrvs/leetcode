class MinStack {
    ArrayList<Integer> elements = new ArrayList();
    ArrayList<Integer> minIndexes = new ArrayList();

    public void push(int x) {
        elements.add(x);
        if (minIndexes.size() == 0 || 
            x < elements.get(minIndexes.get(minIndexes.size() - 1))) {
            minIndexes.add(elements.size() - 1);
        }
    }

    public void pop() {
        if (minIndexes.get(minIndexes.size() - 1) == elements.size() -1 ) {
            minIndexes.remove(minIndexes.size() - 1);
        }
        elements.remove(elements.size() - 1);
    }

    public int top() {
        return elements.get(elements.size() - 1);
    }

    public int getMin() {
        return elements.get(minIndexes.get(minIndexes.size() - 1));
    }
}
