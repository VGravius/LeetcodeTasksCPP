// Link: https://leetcode.com/problems/median-of-two-sorted-arrays
// Problem: Median of Two Sorted Arrays
// Difficulty: Hard

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();

        int len_12 = len1 + len2;
        
        // =====================================================
        // СПОСОБ 1: Слияние до середины (верный, но медленный O(m+n)) Мое решение
        // =====================================================
        /*
        int index = len_12 / 2;
        int prev = 0;
        int current = 0;
        int i = 0, j = 0;
        
        for (int steps = 0; steps <= index; steps++) {
            prev = current;
            
            if (i < nums1.size() && (j >= nums2.size() || nums1[i] <= nums2[j])) {
                current = nums1[i];
                i++;
            } else {
                current = nums2[j];
                j++;
            }
        }
        
        if (len_12 % 2 == 1) {
            return current;
        } else {
            return (prev + current) / 2.0;
        }
        */
        
        // =====================================================
        // СПОСОБ 2: Бинарный поиск (быстрый O(log(min(m,n)))) Верное решение
        // ===================================================== 
        
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;
        
        int left = 0;
        int right = m;
        
        while (left <= right) {
            int i = (left + right) / 2; 
            int j = totalLeft - i;        
            
            int nums1Left = (i == 0) ? INT_MIN : nums1[i - 1];
            int nums1Right = (i == m) ? INT_MAX : nums1[i];
            int nums2Left = (j == 0) ? INT_MIN : nums2[j - 1];
            int nums2Right = (j == n) ? INT_MAX : nums2[j];
            
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if ((m + n) % 2 == 1) {
                    return max(nums1Left, nums2Left);
                } else {
                    return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;
                }
            }
            else if (nums1Left > nums2Right) {
                right = i - 1;
            }
            else {
                left = i + 1;
            }
        }
        
        return 0.0; 
    }
};