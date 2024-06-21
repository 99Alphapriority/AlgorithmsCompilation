class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        auto it = customers.begin();

        int satisfied = accumulate(it, it+minutes, 0);

        for(int i = minutes; i < n; i++)
            satisfied += (1 - grumpy[i])*customers[i];

        int ans = satisfied;

        for(int i = minutes; i < n; i++)
        {
            satisfied -= grumpy[i-minutes] * customers[i-minutes];
            satisfied += grumpy[i] * customers[i];
            ans = max(ans, satisfied);
        }

        return ans;
    }
};
