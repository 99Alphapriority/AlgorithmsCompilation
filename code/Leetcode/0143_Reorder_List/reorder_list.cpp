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
        ListNode *p1 = head->next;
        ListNode *p2 = head;
        ListNode *p3 = NULL;

        while(p2 != NULL)
        {
            p2->next = p3;
            p3 = p2;
            p2 = p1;
            if(p1 != NULL)
            {
                p1 = p1->next;
            }
        }
        return p3;
    }

    void merge(ListNode *l1, ListNode *l2)
    {
        ListNode* p1;
        ListNode* p2;
       while (l1 != NULL) {
            p1 = l1->next;
            if(l2 != NULL)
                p2 = l2->next;
            
            l1->next = l2;
            if (p1 == NULL) {
                break;
            }
            l2->next = p1;
            
            l1 = p1;
            l2 = p2;
        }
    }

    void reorderList(ListNode* head) {
        
        if(head->next == NULL)
            return;
        
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = NULL;

        slow = head;
        fast = reverse(fast);

        merge(slow, fast);
        
    }
};
