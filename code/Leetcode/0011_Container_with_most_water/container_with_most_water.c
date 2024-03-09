int maxArea(int* height, int heightSize) {
    
    int length = 0, breadth = 0, area = 0, maxArea = 0;
    int start = 0;
    int end = (heightSize-1);

    while(start != end)
    {
        breadth = end - start;

        if(height[start] > height[end])
        { 
            length = height[end];
            end --;
        }
        else
        {   
            length = height[start];
            start++;
        }

        area = length * breadth;

        maxArea = (area>maxArea ? area: maxArea);

    }

    return maxArea;
}
