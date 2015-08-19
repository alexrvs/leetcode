class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int left = 1, right = 10, tx = x/10;
        while (tx > 0) {
            tx /= 10;
            left *= 10;
        }
        while (left >= right) {
            if(x / left != x % right / (right / 10)) {
              return false;
            }
            x %= left;
            x = x - x%right;
            left /= 10;
            right *= 10;  
        }
        return true;
    }
};
