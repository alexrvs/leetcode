public class Solution {
    public String getHint(String secret, String guess) {
        int size = secret.length();
        int[] s = new int[10];
        int[] g = new int[10];
        int b = 0;
        for (int i = 0; i < size; i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                b++;
            }
            s[secret.charAt(i) - '0']++;
            g[guess.charAt(i) - '0']++;
        }
        int c = 0;
        for (int i = 0; i < 10; i++) {
            if (s[i] < g[i]) {
                c += s[i];
            } else {
                c += g[i];
            }
        }
        c -= b;
        String res = "" + b + "A" + c + "B";
        return res;
    }
}
