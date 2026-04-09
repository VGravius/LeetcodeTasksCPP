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