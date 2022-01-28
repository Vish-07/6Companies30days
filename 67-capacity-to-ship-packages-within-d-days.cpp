class Solution {
public:
    bool possible(int val, vector<int>& weights, int D)
    {
        int count = 1;
        int i = 0;
        int sum = 0;
        while(i < weights.size())
        {
            if(sum + weights[i] <= val)
            {
                sum += weights[i];
            }
            else
            {
                count++;
                sum = weights[i];
            }
            if(count > D)
                return false;
            i++;
        }
        if(count > D)
            return false;
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int D) 
    {
        int high = 0;
        int low = 0;
        for(int i = 0; i < weights.size(); ++i)
        {
            high += weights[i];
            if(weights[i] > low)
                low = weights[i];
        }
        int ans;
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(possible(mid, weights, D))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};