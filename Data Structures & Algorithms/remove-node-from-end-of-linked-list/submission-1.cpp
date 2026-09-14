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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        auto h = process(head, n);
        if(h) { // this is true only when n is first node
            head = h->next;
        }

        return head;
    }

private:
    ListNode* process(ListNode* head, int& n) {
        if(head == nullptr) {
            return nullptr;
        }

        auto nHead = process(head->next, n);

        n--;

        if(0 == n) {
            return head;
        }

        if(nHead) {
            head->next = nHead->next;
        }

        return nullptr;
    }
};
