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
    void reorderList(ListNode* head) {

        head = process(head, head->next);
        
    }

    ListNode* process(ListNode* head, ListNode* cur) {

        if(cur == nullptr) {
            return head;
        }
        
        head = process(head, cur->next);
        
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* node = nullptr;

        if(head == cur || head->next == cur) {
            cur->next = nullptr;
        } else {
            node = head->next;
            head->next = cur;
            cur->next = node;
        }

        return node;
    }
};
