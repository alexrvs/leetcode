public class Solution {
    public int minCut(String s) {
        int size = s.length();
        boolean[][] isPalindrome = new boolean[size][size];
        int[] numPalindrome = new int[size + 1];
        numPalindrome[0] = 0;

        for (int i = 0; i < size; i++) {
            numPalindrome[i + 1] = size;
            for (int l = 0; l <= i; l++) {
                if (s.charAt(l) == s.charAt(i) && (l + 1 >= i || isPalindrome[l + 1][i - 1])) {
                    isPalindrome[l][i] = true;
                    int cur = numPalindrome[l] + 1;
                    if (cur < numPalindrome[i + 1]) {
                        numPalindrome[i + 1] = cur;
                    }
                }
            }
        }
        
        return numPalindrome[size] - 1;
    }
}