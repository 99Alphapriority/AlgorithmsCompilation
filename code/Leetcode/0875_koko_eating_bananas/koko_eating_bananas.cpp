class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = 0;

        for(int i = 0; i < piles.size(); i++)
        {
            high = max(high, piles[i]);
        }

        int ans = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;
            long int hours = 0;
            for(int i = 0; i < piles.size(); i++)
            {
                hours += ceil((double)piles[i]/mid);
            }

            if(hours <= h)
            {
                ans = min(ans, mid);
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return ans;
    }
};
