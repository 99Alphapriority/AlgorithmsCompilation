/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void join(Node *p1, Node *p2)
    {
        if(p1 != NULL)
            p1->next = p2;
        if(p2 != NULL)
            p2->prev = p1;
    }

    Node* flatten(Node* head) {
        Node* node = head;

        while(node != NULL)
        {
            if(node->child != NULL)
            {
                Node* temp = flatten(node->child);
                Node* next = node->next;
                join(node, temp);
                while(temp->next)
                    temp = temp->next;

                join(temp, next);
                node->child = NULL;
                node = next; 
            }
            else node = node->next;
        }
        return head;
    }
};
