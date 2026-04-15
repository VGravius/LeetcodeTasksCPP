// Link: https://leetcode.com/problems/longest-palindromic-substring
// Problem: Longest Palindromic Substring
// Difficulty: Medium

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0;  // начало самого длинного палиндрома
        int maxLen = 1; // длина самого длинного палиндрома (минимум 1)
        
        // Функция расширения от центра
        auto expand = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Возвращаем длину палиндрома
            return right - left - 1;
        };
        
        for (int i = 0; i < s.length(); i++) {
            // Нечётный палиндром (центр в i)
            int len1 = expand(i, i);
            // Чётный палиндром (центр между i и i+1)
            int len2 = expand(i, i + 1);
            
            int len = max(len1, len2);
            
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        
        return s.substr(start, maxLen);
    }
};