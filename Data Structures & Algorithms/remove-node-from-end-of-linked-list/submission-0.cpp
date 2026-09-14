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
        int nIdx;

        auto h = process(head, nIdx, n);
        if(h) { // this is true only when n is first node
            head = h->next;
        }

        return head;
    }

private:
    ListNode* process(ListNode* head, int& nodeIdx, int n) {
        if(head == nullptr) {
            nodeIdx = 0;
            return nullptr;
        }

        auto nHead = process(head->next, nodeIdx, n);

        nodeIdx++;

        if(nodeIdx == n) {
            return head;
        }

        if(nHead) {
            head->next = nHead->next;
        }

        return nullptr;
    }
};
