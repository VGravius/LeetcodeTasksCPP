// Link: https://leetcode.com/problems/top-k-frequent-elements
// Problem: Top K Frequent Elements
// Difficulty: Medium

class Solution {
    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> freq;
    
            for (int i = 0; i < nums.size(); i++){
                freq[nums[i]]++;
                
            }
    
            vector<pair<int, int>> vec(freq.begin(), freq.end());
    
            sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;  // по частоте (убывание)
            });
    
            vector<int> result;
            for (int i = 0; i < k; i++) {
                result.push_back(vec[i].first);  // берём число
            }
            return result;
    
    
        }
    };
    
    