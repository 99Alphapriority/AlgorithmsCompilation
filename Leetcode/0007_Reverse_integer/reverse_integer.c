int reverse(int x){

    long temp = 0;
    bool msb = false;

    if(x < 0)
    {
        if(-2147483648 == x)
            return 0;

        x *= (-1);
        msb = true; 
    }

    while(x != 0)
    {   
        if((10 * temp) >= 2147483647)
        {   
            printf("exited\n"); 
            return 0;
        }
        temp *= 10;
        temp += (x % 10);
        x /= 10;
    }

    if(msb)
    {
        temp *= (-1);
    }
    return temp;
}
