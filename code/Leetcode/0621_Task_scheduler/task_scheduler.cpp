class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        priority_queue<int> pq;
        vector<int> alphabets(26, 0);
        int time = 0;

        for(char &ch: tasks)
            alphabets[ch - 'A']++;

        for(int i = 0; i< 26; i++)
        {
            if(alphabets[i])
                pq.push(alphabets[i]);
        }

        while(!pq.empty())
        {
            vector<int> temp;
            for(int i = 1; i <= n+1; i++)
            {
                if(!pq.empty())
                {
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int &it: temp)
            {
                if(it > 0)
                    pq.push(it);
            }

            if(pq.empty())
            {
                time += temp.size();
            }
            else
                time += n+1;
        }

        return time;
    }
};
