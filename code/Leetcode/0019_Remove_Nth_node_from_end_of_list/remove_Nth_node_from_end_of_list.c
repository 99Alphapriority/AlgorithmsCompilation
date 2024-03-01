/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode* head)
{
    struct ListNode *p1;
    struct ListNode *p2;
    struct ListNode *p3;

    p3 = head;
    if(p3 != NULL)
        p2 = p3->next;
    if(p2 != NULL)
        p1 = p2->next;
    else
        p1 = p2;
    p3->next = NULL;

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

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    if((head->next == NULL) && (n = 1))
        return head = NULL;

    int mov = 0;
    struct ListNode* p1 = reverse(head);
    struct ListNode* p2 = p1->next;
    struct ListNode* temp = p1;

    if(n == 1)
    {
        p1->next = NULL;
        head = reverse(p2);
        return head;
    }
    else if(n == 2)
    {
        p1->next = p2->next;
        p2->next = NULL;
        head = reverse(p1);
        return head;
    }
    else
    {
        while(mov < n - 2)
        {
            p1 = p2;
            if(p2 != NULL)
                p2 = p2->next;
            mov++;
        }

        p1->next = p2->next;
        p2->next = NULL;

        head = reverse(temp);
        return head;

    }
}
