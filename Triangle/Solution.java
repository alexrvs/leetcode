public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int r = triangle.size();
        int tmp = 0;
        for (int i = 1; i < r; i++) {
            for (int j = 0; j < i + 1; j++) {
                if (j == 0) {
                    tmp = triangle.get(i).get(j) + triangle.get(i - 1).get(j);
                } else if (j == i) {
                    tmp = triangle.get(i).get(j) + triangle.get(i - 1).get(j - 1);
                } else {
                    tmp = triangle.get(i - 1).get(j) < triangle.get(i - 1).get(j - 1) ? triangle.get(i - 1).get(j) : triangle.get(i - 1).get(j - 1);
                    tmp += triangle.get(i).get(j);
                }
                triangle.get(i).set(j, tmp);
            }
        }
        int min = triangle.get(r - 1).get(0);
        for (int i = 1; i < r; i++) {
            tmp = triangle.get(r - 1).get(i);
            if (min > tmp) min = tmp;
        }
        return min;
    }
}
