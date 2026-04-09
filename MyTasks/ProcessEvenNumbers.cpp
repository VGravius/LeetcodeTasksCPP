// Link: Своя задача
// Problem: Process Even Numbers
// Difficulty: Easy
// Task: Написать функцию, которая фильтрует чётные числа из массива
//       и возвращает новый массив только с чётными числами.
// Example:
//   Input:  nums = [1, 2, 3, 4, 5, 6]
//   Output: [2, 4, 6]
// Explanation: Функция проверяет каждое число, если оно чётное -> добавляет в результат.

class Solution {
    public:
        vector<int> processEvenNumbers(vector<int>& nums) {
            // Результат (новый вектор с чётными числами)
            vector<int> result;
            
            // Индекс для прохода по массиву
            int i = 0;
            
            // Лямбда-функция для проверки чётности текущего числа
            // Захватывает nums и i по ссылке (&), чтобы видеть изменения
            auto isEven = [&nums, &i]() {
                return nums[i] % 2 == 0;  // true если число чётное
            };
            
            // Проходим по всем элементам массива
            for (; i < nums.size(); i++) {
                if (isEven()) {               // если число чётное
                    result.push_back(nums[i]); // добавляем в результат
                }
            }
            
            // Возвращаем новый массив с чётными числами
            return result;
        }
    };