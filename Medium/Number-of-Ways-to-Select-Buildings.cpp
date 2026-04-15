// Link: https://leetcode.com/problems/number-of-ways-to-select-buildings
// Problem: Number of Ways to Select Buildings
// Difficulty: Medium (Сложно)

class Solution {
    public:
        long long numberOfWays(string s) {
            long long totalZeros = 0, totalOnes = 0;
            
            // Подсчитываем общее количество 0 и 1
            for (char c : s) {
                if (c == '0') totalZeros++;
                else totalOnes++;
            }
            
            long long leftZeros = 0, leftOnes = 0;
            long long result = 0;
            
            // Проходим по строке, каждый элемент рассматриваем как центр
            for (char c : s) {
                if (c == '0') {
                    // Паттерн 1,0,1: текущий 0 в центре
                    result += leftOnes * (totalOnes - leftOnes);
                    leftZeros++;
                } else { // c == '1'
                    // Паттерн 0,1,0: текущий 1 в центре
                    result += leftZeros * (totalZeros - leftZeros);
                    leftOnes++;
                }
            }
            
            return result;
        }
    };