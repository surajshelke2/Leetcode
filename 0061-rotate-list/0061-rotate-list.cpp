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
    

    ListNode* rotateRight(ListNode* head, int k) {

      if (!head || !head->next || k == 0) return head;

        ListNode* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }

       
        curr->next = head;

      
        k = k % length;
        int stepsToNewHead = length - k;

        curr = head;
        for (int i = 1; i < stepsToNewHead; i++) {
            curr = curr->next;
        }

        
        ListNode* newHead = curr->next;
        curr->next = nullptr;

        return newHead;
    }
};