public class Solution {
    public int lengthLongestPath(String input) {
        int size = input.length();
        List<Integer> layer = new ArrayList<Integer>();
        for (int i = 0; i < size; i++) {
            layer.add(0);
        }
        int curLen = 0;
        int curLayer = 0;
        int maxLen = 0;
        boolean isFile = false;
        for (int i = 0; i <= size; i++) {
            if (i == size || input.charAt(i) == '\n') {
                layer.set(curLayer, curLen);
                if (isFile == true) {
                    int pathLen = 0;
                    for (int j = 0; j <= curLayer; j++) {
                        pathLen += layer.get(j);
                    }
                    pathLen += curLayer;
                    maxLen = maxLen > pathLen ? maxLen : pathLen;
                }
                isFile = false;
                curLayer = 0;
                curLen = 0;
            } else if (input.charAt(i) == '\t') {
                curLayer++;
            } else {
                curLen++;
                if (input.charAt(i) == '.') {
                    if (i + 1 < size && input.charAt(i + 1) != '\t' && input.charAt(i + 1) != '\n') isFile = true;
                }
            }
        }
        return maxLen;
    }
}
