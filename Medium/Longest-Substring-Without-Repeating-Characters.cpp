// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters
// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Храним последний индекс каждого символа
        unordered_map<char, int> lastIndex;
        
        int left = 0;        // левая граница окна
        int maxLen = 0;      // максимальная длина (ответ)
        
        // right — правая граница окна, движется по строке
        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            
            // Если символ уже был И он внутри текущего окна
            if (lastIndex.find(c) != lastIndex.end() && lastIndex[c] >= left) {
                // Перепрыгиваем левую границу на позицию после прошлого вхождения
                left = lastIndex[c] + 1;
            }
            
            // Запоминаем (обновляем) последний индекс этого символа
            lastIndex[c] = right;
            
            // Текущая длина окна
            int currentLen = right - left + 1;
            
            // Обновляем максимум
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
        }
        
        return maxLen;
    }
};