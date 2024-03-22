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
    ListNode* merge(ListNode* list1, ListNode* list2)
    {
        if(list1==NULL )
        {
            return list2;
        }
        if(list2==NULL )
        {
            return list1;
        }
        ListNode* head = new ListNode();
        ListNode*temp=head;

        while(list1&&list2)
        {
          if(list1->val<list2->val)
          {
            temp->next=list1;
            list1=list1->next;
          }
          else{
            temp->next=list2;
            list2=list2->next;
          }
          temp=temp->next;
        }
        if(list1) temp->next = list1;
        if(list2) temp->next = list2;
        return head->next;
    }

    ListNode* divide(vector<ListNode*>& lists, int start, int end)
    {
        if(start > end)
            return NULL;
        
        if(start == end)
            return lists[start];
        
        int mid = start + (end-start) / 2;

        ListNode* left = divide(lists, start, mid);
        ListNode* right = divide(lists, mid + 1, end);

        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) 
            return NULL;

        return divide(lists, 0, lists.size() - 1);
        
    }
};
