public class Solution {
    public int distributeCandies(int[] candies) {
        Set<Integer> numCnt = new HashSet<Integer>();
        for (int i = 0; i < candies.length; i++) {
            if (!numCnt.contains(candies[i])) {
                numCnt.add(candies[i]);
            }
        }
        return candies.length / 2 > numCnt.size() ? numCnt.size() : candies.length / 2;
    }
}