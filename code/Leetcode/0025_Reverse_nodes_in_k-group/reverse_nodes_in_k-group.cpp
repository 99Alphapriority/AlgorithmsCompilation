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
    ListNode* reverseList(ListNode* head, int k)
    {
        ListNode* p1 = head->next;
        ListNode* p2 = head;
        ListNode* p3 = NULL;

        if(k == 1)
            return head;

        while(k > 0)
        {
            p2->next = p3;
            p3 = p2;
            p2 = p1;

            if(p1 != NULL)
                p1 = p1->next;
            
            k--;
        }
               
        return p3;
    }
    bool isPossible(ListNode* start, int k)
    {
        ListNode* temp = start;
        int count = k;

        while(count > 0)
        {
            if(temp ==  NULL)
                return false;
            temp = temp->next;

            count--;
        }

        return true;
    }

    ListNode* helper(ListNode* start, int k)
    {
        int count = k;
        ListNode* temp = start;

        if(isPossible(start, k))
        {
        
            while(count > 0)
            {
                temp = temp->next;
                count--;
            }
         
            ListNode* node = helper(temp, k);
            ListNode* head = reverseList(start, k);

            start->next = node;

            return head;
        }
        return start;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        return helper(head, k);
    }
};
