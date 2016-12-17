public class Solution {
    public int ladderLength(String beginWord, String endWord, Set<String> wordList) {
        Set<String> fromBegin = new HashSet<String>();
        Set<String> fromEnd = new HashSet<String>();
        int wordLen = beginWord.length();
        fromBegin.add(beginWord);
        fromEnd.add(endWord);
        int len = 0;
        Set<String> visited = new HashSet<String>();
        while (!fromBegin.isEmpty() && !fromEnd.isEmpty()) {
            if (fromBegin.size() > fromEnd.size()) {
                Set<String> tmp = fromBegin;
                fromBegin = fromEnd;
                fromEnd = tmp;
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
                            return len + 2;
                        }
                        
                        if (!visited.contains(newWord) && wordList.contains(newWord)) {
                            newWords.add(newWord);
                            visited.add(newWord);
                        }
                        
                        chars[i] = old;
                    }
                }
            }
            
            fromBegin = newWords;
            len++;
        }
        
        return 0;
    }
}