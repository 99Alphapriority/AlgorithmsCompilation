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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* p1 = head->next;
        ListNode* p2 = head;
        ListNode* p3 = NULL;
        int k = 2;

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

    bool isPairPossible(ListNode* head)
    {
        int count = 2;
        ListNode* temp = head;

        while(count-- > 0)
        {
            if(temp == NULL)
                return false;

            temp = temp->next;
        }
        return true;
    }

    ListNode* helper(ListNode* start)
    {   
        ListNode* temp = start;
        ListNode* node = NULL;
        ListNode* head = NULL;
        int count = 2;

        if(isPairPossible(start))
        {   
            while(count > 0)
            {
                temp = temp->next;
                count--;
            }

            if(temp != NULL)
                node = helper(temp);
            
            head = reverseList(start);

            start->next = node;
            return head;
        }
        return start;
    }
    
    ListNode* swapPairs(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;
        
        return helper(head);
    }
};
