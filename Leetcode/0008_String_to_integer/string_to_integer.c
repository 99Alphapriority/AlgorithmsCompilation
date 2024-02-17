int myAtoi(char* s) {
    
    int length = strlen(s);
    int i = 0;
    long temp = 0;
    bool flag = false;
    bool numFlag = false;

    while(i < length)
    {
        if(' ' == s[i])
        {   
            if(numFlag)
            {
                break;
            }
            i++;
        }
        else if ('+' == s[i])
        {
            if(numFlag)
            {
                //temp = 0;
                break;
            }

            if(('+' == s[i+1]) || ('-' == s[i+1]) || (' ' == s[i+1]))
            {
                temp = 0;
                break;
            }
            else
                i++;
        }
        else if('-' == s[i])
        {
            if(numFlag)
            {
                //temp = 0;
                break;
            }
            
            flag = true;
            
            if(('+' == s[i+1]) || ('-' == s[i+1]) || (' ' == s[i+1]))
            {
                temp = 0;
                break;
            }
            else
                i++;
        }
        else if((s[i] >= 48) && (s[i] <=57))
        {
            numFlag = true;
            if((temp*10) > 2147483647)
            {
                temp = 2147483647;
                if(flag)
                    temp++;
                break;
            }

            temp*= 10;
            temp+= (s[i] + 2)%10;

            if((2147483648 <= temp) && flag)
                return 2147483648;
            else if(2147483647 < temp)
                return 2147483647;
            i++;
        }
        else
            break;

    }

    if(flag)
        temp *= (-1);

    return temp;
}
