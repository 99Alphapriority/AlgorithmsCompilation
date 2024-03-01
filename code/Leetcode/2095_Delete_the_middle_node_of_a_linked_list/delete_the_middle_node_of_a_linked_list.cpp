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
    ListNode* deleteMiddle(ListNode* head) {

        if(head->next == NULL)
            return NULL;

        ListNode *slow = head;
        ListNode *fast = head->next;
        ListNode *prev = NULL;

        if(fast->next == NULL)
        {
            slow->next = NULL;
            return head;
        }

        while(fast != NULL && fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;

            if(fast == NULL)
            {
                prev->next = slow->next;
                //free(slow);
                return head;
            }
            else if(fast->next == NULL)
            {
                prev = slow;
                slow = slow->next;
                prev->next = slow->next;
                //free(slow);
                return head;
            }
        }

        return head;
        
    }
};
