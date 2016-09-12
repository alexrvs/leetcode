public class Solution {

    private static final int mask1 = 0x0080; // 1000 0000
    private static final int byte1 = 0x0000; // 0000 0000
    private static final int mask2 = 0x00e0; // 1110 0000
    private static final int byte2 = 0x00c0; // 1100 0000
    private static final int mask3 = 0x00f0; // 1111 0000
    private static final int byte3 = 0x00e0; // 1110 0000
    private static final int mask4 = 0x00f8; // 1111 1000
    private static final int byte4 = 0x00f0; // 1111 0000
    private static final int mask  = 0x00c0; // 1100 0000
    private static final int pref  = 0x0080; // 1000 0000

    public boolean validUtf8(int[] data) {
        int dataSize = data.length;
        for (int i = 0; i < dataSize; i++) {
            if ((data[i] & mask1) == byte1) {
                continue;
            } else if ((data[i] & mask2) == byte2) {
                if (i + 1 >= dataSize) return false;
                if ((data[i + 1] & mask) != pref) return false;
                i = i + 1;
            } else if ((data[i] & mask3) == byte3) {
                if (i + 2 >= dataSize) return false;
                if ((data[i + 1] & mask) != pref) return false;
                if ((data[i + 2] & mask) != pref) return false;
                i = i + 2;
            } else if ((data[i] & mask4) == byte4) {
                if (i + 3 >= dataSize) return false;
                if ((data[i + 1] & mask) != pref) return false;
                if ((data[i + 2] & mask) != pref) return false;
                if ((data[i + 3] & mask) != pref) return false;
                i = i + 3;
            } else {
                return false;
            }
        }
        return true;
    }
}
