// Link: https://leetcode.com/problems/reverse-integer/
// Problem: Reverse Integer
// Difficulty: Medium

class Solution {
    public:
        int reverse(int x) {
            int reversed = 0;
            
            while (x != 0) {
                int digit = x % 10;
                x /= 10;
                
                // Проверка на переполнение (32-bit integer range)
                // INT_MAX = 2147483647, INT_MIN = -2147483648
                if (reversed > INT_MAX / 10 || 
                    (reversed == INT_MAX / 10 && digit > 7)) {
                    return 0;
                }
                if (reversed < INT_MIN / 10 || 
                    (reversed == INT_MIN / 10 && digit < -8)) {
                    return 0;
                }
                
                reversed = reversed * 10 + digit;
            }
            
            return reversed;
        }
    };