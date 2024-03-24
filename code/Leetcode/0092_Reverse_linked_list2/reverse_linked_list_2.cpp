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
    ListNode* reverse(ListNode* start, int n)
    {
        ListNode* p2 = start;
        ListNode* p1 = start->next;
        ListNode* p3 = NULL;
        ListNode* temp = start;
        
        while(n)
        {
            p2->next = p3;
            p3 = p2;
            p2 = p1;

            if(p1)
                p1 = p1->next;

            n--;
        }

        temp->next = p2;

        return p3;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode* start = NULL;
        ListNode* temp = head;
        ListNode* prev = NULL;
        int i = 1;

        if(head->next == NULL)
            return head;

        if(left == 1)
        {
            temp = reverse(head, right - left + 1);
            return temp;
        }
        else if(left == 2)
        {
            temp = head;
            start = head->next;
            temp->next = reverse(start, right - left + 1);

            return temp;
        }
        else
        {
            start = head;

            while(i < left)
            {
                i++;
                prev = start;
                start = start->next;
            }

            prev->next = reverse(start, right - left + 1);
            return head;
        } 

        return NULL;
    }
};
