typedef struct stack{
    char val;
    struct stack *next;
}stack_p;

stack_p *head;

void push(char c)
{
    stack_p *new = (stack_p*)malloc(sizeof(stack_p));

    new->val = c;
    new->next = head;

    head = new;
    new = NULL;
}

void pop()
{
    stack_p *temp = head;

    if(head->next != NULL)
        head = head->next;
    
    free(temp);
    temp = NULL;
}

bool isValid(char* s) {
    
    int i = 0;
    
    head = (stack_p*)malloc(sizeof(stack_p));

    head->val = -1;
    head->next = NULL;

    if((s[0] == ')') || (s[0] == ']') || (s[0] == '}'))
        return false;

    while(s[i] != '\0')
    {

        if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
        {
            push(s[i]);
        }
        else if((s[i] == ')') && (head->val == '('))
        {
            pop();   
        }
        else if((s[i] == ']') && (head->val == '['))
        {
            pop();
        }
        else if((s[i] == '}') && (head->val == '{'))
        {
            pop();
        }
        else
            return false;
        
        i++;
    }

    if(head->val == -1)
        return true;
    else
        return false;      
}
