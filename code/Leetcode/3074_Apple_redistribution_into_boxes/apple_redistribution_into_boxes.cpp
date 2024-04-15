class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int n = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int> ());
        int count = 0;

        for(int i = 0; i < capacity.size(); i++)
        {
            n -= capacity[i];
            count++;

            if(n <= 0)
                return count;
        }

        return 0;
    }
};
