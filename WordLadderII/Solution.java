public class Solution {
    
    private void markStep(Map<String, Set<String>> steps, String from, String to) {
        if (!steps.containsKey(from)) {
            steps.put(from, new HashSet<String>());
        }
        steps.get(from).add(to);
        return;
    }
    
    private void getPaths(String beginWord, String endWord, Map<String, Set<String>> steps, List<List<String>> paths, List<String> path) {
        Set<String> nextSet = steps.get(beginWord);
        path.add(beginWord);
        System.out.println(beginWord);
        if (beginWord.equals(endWord)) {
            paths.add(new ArrayList<String>(path));
        } else if (null != nextSet){
            for (String nextWord : nextSet) {
                getPaths(nextWord, endWord, steps, paths, path);
            }
        }
        path.remove(path.size() - 1);
        return;
    }
    
    public List<List<String>> findLadders(String beginWord, String endWord, Set<String> wordList) {
        Set<String> fromBegin = new HashSet<String>();
        Set<String> fromEnd = new HashSet<String>();
        int wordLen = beginWord.length();
        Map<String, Set<String>> steps = new HashMap<String, Set<String>>();
        Set<String> visited = new HashSet<String>();
        boolean isBeginToEnd = true;
        boolean isReached = false;
        fromBegin.add(beginWord);
        fromEnd.add(endWord);
        visited.add(beginWord);
        visited.add(endWord);
        while (false == isReached && !fromBegin.isEmpty() && !fromEnd.isEmpty()) {
            if (fromBegin.size() > fromEnd.size()) {
                Set<String> tmp = fromBegin;
                fromBegin = fromEnd;
                fromEnd = tmp;
                isBeginToEnd = ! isBeginToEnd;
            }
            Set<String> newWords = new HashSet<String>();
            for (String word : fromBegin) {
                char[] chars = word.toCharArray();
                for (int i = 0; i < wordLen; i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        char old = chars[i];
                        chars[i] = c;
                        String newWord = String.valueOf(chars);
                        
                        if (fromEnd.contains(newWord)) {
                            isReached = true;
                            if (isBeginToEnd) {
                                markStep(steps, word, newWord);
                            } else {
                                markStep(steps, newWord, word);
                            }
                        } else if (!visited.contains(newWord) && wordList.contains(newWord)) {
                            newWords.add(newWord);
                            visited.add(newWord);
                            if (isBeginToEnd) {
                                markStep(steps, word, newWord);
                            } else {
                                markStep(steps, newWord, word);
                            }
                        }
                        
                        chars[i] = old;
                    }
                }
            }
            
            fromBegin = newWords;
        }
        
        List<List<String>> paths = new ArrayList<List<String>>();
        List<String> path = new ArrayList<String>();
        
        getPaths(beginWord, endWord, steps, paths, path);
        
        return paths;
    }
}