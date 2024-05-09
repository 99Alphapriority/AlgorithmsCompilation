class Solution {
public:
    int next(int n)
    {
        int sum = 0;

        while(n > 0)
        {
            int digit = n % 10;
            n /= 10;
            sum += pow(digit, 2);
        }
        return sum;
    }

    bool isHappy(int n) {

        int slow = n;
        int fast = next(n);

        while(slow != fast && fast != 1)
        {
            slow = next(slow);
            fast = next(next(fast));
        }

        if(fast == 1)
            return true;
        
        return false;
    }
};
