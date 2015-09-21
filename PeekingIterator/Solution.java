// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
class PeekingIterator implements Iterator<Integer> {

    Iterator<Integer> iter;
    Integer mPeek;
    boolean peeked;

	public PeekingIterator(Iterator<Integer> iterator) {
	    // initialize any member here.
	    iter = iterator;
	    peeked = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	public Integer peek() {
        if (!peeked && iter.hasNext()) {
            peeked = true;
            mPeek = iter.next();
        }
        return mPeek;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	@Override
	public Integer next() {
	    if (peeked) {
	        peeked = false;
	        return mPeek;
	    } else {
	        return iter.next();
	    }
	}

	@Override
	public boolean hasNext() {
	    return peeked || iter.hasNext();
	}
}
