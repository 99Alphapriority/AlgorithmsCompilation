class MinStack {
public:

    typedef struct node{
        int value;
        struct node* next;
    }listNode;

    listNode* head = NULL;
    listNode* head_min = NULL;
    int minVal = 0;

    MinStack() {

        //head = (listNode*)malloc(sizeof(listNode));
        //head_min  = (listNode*)malloc(sizeof(listNode));
        
    }
    
    void push(int val) {

        listNode *temp = (listNode*)malloc(sizeof(listNode));
        listNode *temp_min = (listNode*)malloc(sizeof(listNode));

        temp->value = val;
        if(head != NULL)
            temp->next = head;
        else
            temp->next = NULL;

        head = temp;

        if(head_min == NULL)
        {
            minVal = val;
            //printf("val: %d\n",val);
        }
        else
        {
            if(val < minVal)
                minVal = val;
        }

        temp_min->value = minVal;
        if(head_min != NULL)
        {
            temp_min->next = head_min;
        }
        else
            temp_min->next = NULL;
        
        head_min = temp_min;

        //printf("min stack: %d\n",head_min->value);

        temp = NULL;
        temp_min = NULL;
        
    }
    
    void pop() {

        if(NULL == head)
            return;

        listNode* temp = head;
        listNode* temp_min = head_min;

        head = temp->next;
        temp->next = NULL;

        head_min = temp_min->next;
        if(head_min != NULL)
            minVal = head_min->value;
        temp_min->next = NULL;

        //printf("head->val %d head_min->val %d\n",head->value, head_min->value);

        free(temp);
        free(temp_min);
    }
    
    int top() {

        if(NULL == head)
            return NULL;
        
        return head->value;
        
    }
    
    int getMin() {
        if(NULL == head_min)
            return NULL;
        
        return head_min->value;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
