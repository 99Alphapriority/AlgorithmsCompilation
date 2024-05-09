class Solution {
public:
    int sum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            int digit = n % 10;
            n /= 10;
            sum += digit;
        }
        return sum;
    }

    int addDigits(int num) {
        
        while(num > 9)
        {
            num = sum(num);
        }
        return num;
    }
};
