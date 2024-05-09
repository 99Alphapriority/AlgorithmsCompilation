class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int curr = arr[n-1];
        int temp = 0;
        arr[n-1] = -1;

        for(int i = n - 2; i >= 0; i--)
        {
            temp = arr[i];
            arr[i] = curr;
            curr = max(curr, temp);
        }
        return arr;
    }
};
