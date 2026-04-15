// Link: https://leetcode.com/problems/top-k-frequent-words
// Problem: Top K Frequent Words
// Difficulty: Medium

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        unordered_map<string, int> freq;

        for (int i = 0; i < words.size(); i++){
            freq[words[i]]++;
        }

        vector<pair<string, int>> vec(freq.begin(), freq.end());


        sort(vec.begin(), vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;  // по частоте (убывание)
                }
            return a.first < b.first;        // по алфавиту (возрастание)
        });

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(vec[i].first);  // берём только слово (.first), а не частоту
        }
        return result;
    }
};