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
    ListNode* reverse(ListNode* head)
    {
        if((head == NULL) || (head->next == NULL))
            return head;
        
        ListNode* p1 = head->next;
        ListNode* p2 = head;
        ListNode* p3 = NULL;

        while(p2 != NULL)
        {
            p2->next = p3;
            p3 = p2;
            p2 = p1;

            if(p1 != NULL)
                p1 = p1->next;
        }

        return p3;
    }

    ListNode* doubleIt(ListNode* head) {

        ListNode* rev_head = reverse(head);
        ListNode* temp = rev_head;
        ListNode* lastNode = NULL;
        int carry = 0;

        while(temp != NULL)
        {
            temp->val *= 2;

            if(carry)
            {
                temp->val += carry;
                carry = 0;
            }

            if(temp->val >= 10)
            {
                carry = temp->val / 10;
                temp->val %= 10;
            }

            lastNode = temp;
            temp = temp->next;
        }

        if(carry)
        {
            lastNode->next = new ListNode(carry);
            lastNode->next->next = NULL;
            
        }

        return reverse(rev_head);
    }
};
