// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list
// Problem: Remove Duplicates from Sorted List
// Difficulty: Easy


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        if (head == nullptr){
            return nullptr;
        }
        else if (current->next == nullptr) {
            return head; 
        }

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                current->next = current->next->next;  // удаляем дубликат
            } else {
                current = current->next;  // двигаемся дальше
            }
        }
        return head; 
    }
};