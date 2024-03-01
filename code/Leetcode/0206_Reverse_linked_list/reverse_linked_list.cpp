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
    ListNode* reverseList(ListNode* head) {
        ListNode *p1, *p2, *p3;

        if((head == NULL) || (head->next == NULL))
            return head;
        
        p1 = head->next;
        p2 = head;
        p3 = NULL;

        while(p2 !=  NULL)
        {
            p2->next = p3;
            p3 = p2;
            p2 = p1;
            if(p1)
                p1 = p1->next;
        }

        return p3;
    }
};
