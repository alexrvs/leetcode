public class Solution {
    public List<List<String>> partition(String s) {
        int size = s.length();
        List<List<String>>[] res = new List[size + 1];
        boolean[][] isPalindrome = new boolean[size][size];
        res[0] = new ArrayList<List<String>>();
        res[0].add(new ArrayList<String>());
        
        for (int i = 0; i < size; i++) {
            res[i + 1] = new ArrayList<List<String>>();
            for (int l = 0; l <= i; l++) {
                if (s.charAt(l) == s.charAt(i) && (l + 1 >= i || isPalindrome[l + 1][i - 1])) {
                    isPalindrome[l][i] = true;
                    String substr = s.substring(l, i + 1);
                    for (List<String> list : res[l]) {
                        List<String> newList = new ArrayList<String>(list);
                        newList.add(substr);
                        res[i + 1].add(newList);
                    }
                }
            }
        }
        return res[size];
    }
}