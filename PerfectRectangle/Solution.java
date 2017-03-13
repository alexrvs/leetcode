public class Solution {
    public boolean isRectangleCover(int[][] rectangles) {
        if (rectangles.length == 0 || rectangles[0].length == 0) return false;

        int x1 = Integer.MAX_VALUE;
        int x2 = Integer.MIN_VALUE;
        int y1 = Integer.MAX_VALUE;
        int y2 = Integer.MIN_VALUE;
        
        HashSet<String> points = new HashSet<String>();
        int area = 0;
        
        for (int[] rect : rectangles) {
            x1 = Math.min(rect[0], x1);
            y1 = Math.min(rect[1], y1);
            x2 = Math.max(rect[2], x2);
            y2 = Math.max(rect[3], y2);
            
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
            
            String s1 = rect[0] + " " + rect[1];
            String s2 = rect[0] + " " + rect[3];
            String s3 = rect[2] + " " + rect[3];
            String s4 = rect[2] + " " + rect[1];
            
            if (!points.add(s1)) points.remove(s1);
            if (!points.add(s2)) points.remove(s2);
            if (!points.add(s3)) points.remove(s3);
            if (!points.add(s4)) points.remove(s4);
        }
        
        if (!points.contains(x1 + " " + y1) || 
            !points.contains(x1 + " " + y2) || 
            !points.contains(x2 + " " + y1) || 
            !points.contains(x2 + " " + y2) || 
            points.size() != 4) return false;
        
        return (area == (x2 - x1) * (y2 - y1));
    }
}