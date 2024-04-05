class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty())
        {
            left.push(num);
            return;
        }

        if(left.size() > right.size())
        {
            if(left.top() < num)
                right.push(num);
            else
            {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
        }
        else
        {
            if(right.top() > num)
                left.push(num);
            else
            {
                left.push(right.top());
                right.pop();
                right.push(num);
            }
        }

    }
    
    double findMedian() {
        double result = 0.0;

        if(left.size() == right.size())
            result = (left.top() + right.top()) / 2.0;
        else if(left.size() > right.size())
            result = (double) left.top();
        else
            result = (double) right.top();

        return result;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
