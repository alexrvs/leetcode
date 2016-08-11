class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> nums(26, 0);
        for (int i = 0; i < magazine.size(); i++) {
            nums[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++) {
            nums[ransomNote[i] - 'a']--;
            if (nums[ransomNote[i] - 'a'] < 0) return false;
        }
        return true;
    }
};
