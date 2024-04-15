class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        long size = mass;
        sort(asteroids.begin(), asteroids.end());

        for(int i = 0; i < asteroids.size(); i++)
        {
            if(size >= asteroids[i])
                size += asteroids[i];
            else
                return false;
        }

        return true;        
    }
};
