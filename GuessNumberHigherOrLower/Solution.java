/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        int l = 1;
        int r = n;
        int m = 0;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (guess(m) > 0) {
                l = m + 1;
            } else if (guess(m) == 0) {
                return m;
            } else {
                r = m - 1;
            }
        }
        return m;
    }
}
