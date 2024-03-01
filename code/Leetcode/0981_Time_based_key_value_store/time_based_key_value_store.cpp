class TimeMap {
private:
    unordered_map <string, vector<pair<int, string>>> mp;

public:

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        
        if(mp.find(key) == mp.end())
        {
            return "";
        }

        int left = 0;
        int right = mp[key].size() - 1;

        while(left <= right)
        {
            int mid = left + (right - left)/2;
            
            if(mp[key][mid].first < timestamp)
                left = mid + 1;
            else if(mp[key][mid].first > timestamp)
                right = mid - 1;
            else
                return mp[key][mid].second;
        }

        if(right >= 0)
        {
            return mp[key][right].second;
        }

        return "";
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
