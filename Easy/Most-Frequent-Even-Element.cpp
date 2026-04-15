// // Link: https://leetcode.com/problems/most-frequent-even-element/
// // Problem: Most Frequent Even Element
// // Difficulty: Easy

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> freq;

        for (int num : nums) {
            if (num % 2 == 0) {  // только чётные
                freq[num]++;
            }
        }

        if (freq.empty()) return -1;

        int result = -1;
        int maxFreq = 0;

        for (auto& p : freq) {
            int num = p.first;
            int count = p.second;

            if (count > maxFreq || (count == maxFreq && num < result)) {
                maxFreq = count;
                result = num;
            }
        }

    return result;
    }
};