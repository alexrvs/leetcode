public class Solution {
    private class EnvelopeComp implements Comparator<int[]> {

        public int compare(int[] env1, int[] env2) {
            if (env1[0] != env2[0]) return env1[0] - env2[0];
            else return env2[1] - env1[1];
        }
    }

    public int maxEnvelopes(int[][] envelopes) {
        if (envelopes.length == 0) return 0;
        Arrays.sort(envelopes, new EnvelopeComp());
        int dp[] = new int[envelopes.length];
        int len = 0;
        for (int[] envelope : envelopes){
            int index = Arrays.binarySearch(dp, 0, len, envelope[1]);
            if (index < 0) index = -(index + 1);
            dp[index] = envelope[1];
            if (index == len) len++;
        }
        return len;
    }
}
