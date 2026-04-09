// Link: My Task
// Problem: Process Negative Numbers (square them)
// Difficulty: Easy
// Task: Дан массив целых чисел.
//       Нужно с помощью лямбда-функции:
//       1. Отобрать только отрицательные числа
//       2. Каждое отрицательное число возвести в квадрат
//       3. Вернуть новый массив
// Example:
//   Input:  [-3, 4, -1, 7, -5, 2, -8]
//   Output: [9, 1, 25, 64]
// Explanation: отрицательные числа: -3, -1, -5, -8 → возводим в квадрат → 9, 1, 25, 64

class Solution {
    public:
        vector<int> processNegativeNumbers(vector<int>& nums) {
            vector<int> result;
            int i = 0;
            auto isNegative = [&nums, &i]() {
                return nums[i] < 0;
            };
            for (; i < nums.size(); i++) {
                if (isNegative()) result.push_back(nums[i] * nums[i]);
            }
            return result;
        }
    };