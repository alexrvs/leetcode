/**
 * Definition for undirected graph.
 * class UndirectedGraphNode {
 *     int label;
 *     List<UndirectedGraphNode> neighbors;
 *     UndirectedGraphNode(int x) { label = x; neighbors = new ArrayList<UndirectedGraphNode>(); }
 * };
 */
public class Solution {
    
    private Map<Object, Object> mapOrigToNew = new HashMap<Object, Object>();
    
    private UndirectedGraphNode getNewNode(UndirectedGraphNode cur) {
        if (!mapOrigToNew.containsKey(cur)) {
            mapOrigToNew.put(cur, new UndirectedGraphNode(cur.label));
        }
        UndirectedGraphNode newNode = (UndirectedGraphNode) mapOrigToNew.get(cur);
        return newNode;
    }
    
    public UndirectedGraphNode cloneGraph(UndirectedGraphNode node) {
        if (node == null) return null;
        Map<Object, Object> mapOrigToNew = new HashMap<Object, Object>();
        List<Object> toVisit = new ArrayList<Object>();
        toVisit.add(node);
        int cnt = 0;
        UndirectedGraphNode res = null;
        while (cnt < toVisit.size()) {
            UndirectedGraphNode cur = (UndirectedGraphNode) toVisit.get(cnt);
            UndirectedGraphNode newNode = getNewNode(cur);
            if (res == null) res = newNode;
            for (UndirectedGraphNode neigh : cur.neighbors) {
                UndirectedGraphNode newNeigh = getNewNode(neigh);
                newNode.neighbors.add(newNeigh);
                if (!toVisit.contains(neigh)) {
                    toVisit.add(neigh);
                }
            }
            cnt++;
        }
        
        return res;
    }
}