// Link: https://leetcode.com/problems/string-to-integer-atoi/
// Problem: String to Integer (atoi)
// Difficulty: Medium

class Solution {
public:
    int myAtoi(string s) {
        char testChars[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        if (s.length() > 200) {
            return 0;
        }
        int i = 0;
        int n = s.length();
        while (i < n && s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }
        auto isDigit = [&](char c) {
            for (char d : testChars) {
                if (c == d) return true;
            }
            return false;
        };
        long long result = 0;
        while (i < n && isDigit(s[i])) {
            result = result * 10 + (s[i] - '0');
            i++;
            
            if (result * sign > INT_MAX) return INT_MAX;
            if (result * sign < INT_MIN) return INT_MIN;
        }
        
        return (int)(result * sign);
    }
};