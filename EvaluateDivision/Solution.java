public class Solution {
    public double[] calcEquation(String[][] equations, double[] values, String[][] queries) {
        int size = equations.length;
        Map<String, Map<String, Double>> map = new HashMap<String, Map<String, Double>>();
        
        for (int i = 0; i < equations.length; i++) {
            String src = equations[i][0];
            String dest = equations[i][1];
            if (!map.containsKey(src)) {
                map.put(src, new HashMap<String, Double>());
                map.get(src).put(src, 1.0);
            }
            map.get(src).put(dest, values[i]);
            if (!map.containsKey(dest)) {
                map.put(dest, new HashMap<String, Double>());
                map.get(dest).put(dest, 1.0);
            }
            map.get(dest).put(src, 1.0 / values[i]);
        }
        
        for (String m : map.keySet()) {
            for (String src : map.get(m).keySet()) {
                for (String dest : map.get(m).keySet()) {
                    double val = map.get(src).get(m) * map.get(m).get(dest);
                    map.get(src).put(dest, val);
                }
            }
        }
        
        double[] res = new double[queries.length];
        for (int i = 0; i < queries.length; i++) {
            String src = queries[i][0];
            String dest = queries[i][1];
            if (map.containsKey(src) && map.get(src).containsKey(dest)) {
                res[i] = map.get(src).get(dest);
            } else {
                res[i] = -1.0;
            }
        }
        return res;
    }
}