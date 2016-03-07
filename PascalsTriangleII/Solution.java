public class Solution {
    public List<Integer> getRow(int rowIndex) {
        int[] row = new int[rowIndex + 1];
        row[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 1; j--) {
                row[j] += row[j - 1];
            }
        }
        List<Integer> res = new ArrayList<Integer>();
        for (int i = 0; i <= rowIndex; i++) {
            res.add(row[i]);
        }
        return res;
    }
}
