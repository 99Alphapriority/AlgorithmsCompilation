class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int size = position.size();
        vector<pair<int, double>> car;
        double time = 0.0, maxTime = 0.0;
        int result = 0;

        for(int i = 0; i < size; i++)
        {
            time = (double)(target - position[i]) / speed[i];

            car.push_back({position[i],time});
        }

        sort(car.begin(), car.end());

        for(int i = size -1; i >= 0; i--)
        {
            time = car[i].second;
            if(time > maxTime)
            {
                maxTime = time;
                result++;
            }
        }
        
        return result;
    }
};
