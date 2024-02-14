/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* l3_p = NULL;
    struct ListNode* temp_p;
    int carryOn = 0;

    l3_p = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp_p = l3_p;     //to keep track of head of the list

    do{
        l3_p->val = (l1?l1->val:0) + (l2?l2->val:0) + carryOn;
        carryOn = l3_p->val/10;
        l3_p->val %= 10;
        l3_p->next = NULL;

        l1 = (l1?l1->next:NULL);
        l2 = (l2?l2->next:NULL);
        
        if( (NULL != l1) || (NULL != l2) || (0 < carryOn) )
        {
            l3_p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            l3_p = l3_p->next;
        }

    }while((!((NULL == l1)&&(NULL == l2))) || carryOn );
    
    return temp_p;   
}
