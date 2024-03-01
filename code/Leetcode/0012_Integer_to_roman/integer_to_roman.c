char* intToRoman(int num) {
    
    char *ans = (char*)malloc(16 * sizeof(char));
    memset(ans, '\0', 16*sizeof(char));
    int i = 0;
    int romanSym = 0;
    
    romanSym = num/1000;
    num %= 1000;

    while(romanSym)
    {
        ans[i++] = 'M';
        romanSym--;
    }

    romanSym = num/900;
    num %= 900; 

    if(romanSym)
    {
        ans[i++] = 'C';
        ans[i++] = 'M';
    }

    romanSym = num/500;
    num %= 500; 

    if(romanSym)
    {
        ans[i++] = 'D';
    }

    romanSym = num/400;
    num %= 400; 

    if(romanSym)
    {
        ans[i++] = 'C';
        ans[i++] = 'D';
    }

    romanSym = num/100;
    num %= 100; 

    while(romanSym)
    {
        ans[i++] = 'C';
        romanSym--;
    }

    romanSym = num/90;
    num %= 90;

    if(romanSym)
    {
        ans[i++] = 'X';
        ans[i++] = 'C';
    }

    romanSym = num/50;
    num %= 50; 

    if(romanSym)
    {
        ans[i++] = 'L';
    }

    romanSym = num/40;
    num %= 40; 

    if(romanSym)
    {
        ans[i++] = 'X';
        ans[i++] = 'L';
    }

    romanSym = num/10;
    num %= 10;

    while(romanSym)
    {
        ans[i++] = 'X';
        romanSym--;
    }

    romanSym = num/9;
    num %= 9; 

    if(romanSym)
    {
        ans[i++] = 'I';
        ans[i++] = 'X';
    }

    romanSym = num/5;
    num %= 5; 

    if(romanSym)
    {
        ans[i++] = 'V';
    }

    romanSym = num/4;
    num %= 4; 

    if(romanSym)
    {
        ans[i++] = 'I';
        ans[i++] = 'V';
    }

    romanSym = num/1; 

    while(romanSym)
    {
        ans[i++] = 'I';
        romanSym--;
    }

    ans[15] = '\0';

    return ans;
}
