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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carry = 0, val;
        int n1 = 0, n2 = 0;

        auto ll1 = l1, ll2 = l2, lastL1 = l1, lastL2 = l2;

        while(l1 || l2) {

            val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = val/10;

            if(l1) {
                n1++;
                l1->val = val%10;

                lastL1 = l1;
                l1 = l1->next;
                
            }

            if(l2) {
                n2++;
                l2->val = val%10;

                lastL2 = l2;
                l2 = l2->next;
            }
        }

        if(carry > 0) {

            ListNode* n = new ListNode(carry, nullptr);

            if(n1 > n2) {
                lastL1->next = n;
            }

            lastL2->next = n;
        }

        return n1 > n2 ? ll1 : ll2;
    }
};
