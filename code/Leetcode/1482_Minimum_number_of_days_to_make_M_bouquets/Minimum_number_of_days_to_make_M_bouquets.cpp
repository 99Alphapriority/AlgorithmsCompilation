class Solution {
public:
    int n;
    int solve(int mid, vector<int>& bloomDay, int k)
    {
        int flowers = 0;
        int bouquet = 0;

        for(int i = 0; i < n; i++)
        {
            if(mid >= bloomDay[i])
            {
                flowers++;
                if(flowers == k)
                {    
                    bouquet++;
                    flowers = 0;
                }
            }
            else
                flowers = 0;
        }
        return bouquet;        
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        n = bloomDay.size();
        int minDay = INT_MAX, maxDay = INT_MIN;
        
        if( m > n/k)
            return -1;
        
        int i = 0;
        int j = INT_MIN;

        for(int k = 0; k < n; k++)
            j = max(j, bloomDay[k]);
        int mid; 
        int ans = INT_MAX;

        while(i <= j)
        {
            mid = i + (j - i)/2;
            if(solve(mid, bloomDay, k) >= m)
            {
                j = mid - 1;
            }
            else
                i = mid + 1;
        }
        return i;
    }
};
