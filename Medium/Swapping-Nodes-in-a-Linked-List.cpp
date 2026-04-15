// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list
// Problem: Swapping Nodes in a Linked List
// Difficulty: Medium (Решено самостоятельно)


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
    ListNode* swapNodes(ListNode* head, int k) {
        if (head == nullptr || k == 0){
            return nullptr;
        }
        ListNode *fast = head, *slow = head, *first = head;

        bool flag = true;
        int count = 1;


        while(fast != nullptr){
            
            if (count != k){
                fast=fast->next;
                count++;
                continue;
            }
            else if (count == k && flag == true){
                first = fast;
                flag = false;
            }


            if (fast->next == nullptr){
                swap(first->val, slow->val);
                return head;
            }

            slow = slow->next;
            fast=fast->next;

        }  
        return head;  
    }
};