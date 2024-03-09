bool isPalindrome(int x) {
    
    int temp = x;
    long check = 0;

    if(0 > x)
        return false;

    if(0 == x/10)
        return true;
    
    while(0 < x)
    {
        if(2147483647 < (check * 10))
            return false;
        check *= 10;
        check += x%10;
        x/=10;
    }

    if(check == temp)
        return true;
    else 
        return false;
}
