class Solution {
public:
    bool isPossible(int val, int h, vector<int>& piles)
    {
        for(int i = 0; i < piles.size(); ++i)
        {
            h -= (piles[i] / val);
            if(piles[i] % val > 0)
                h--;
            // cout << h << endl;
            if(h < 0)
                return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int high = 0, low = 1;
        int n = piles.size();
        
        for(int i = 0; i < n; ++i)
        {
            high = max(high, piles[i]);
        }  
        
        int ans = high;
        
        while(low <= high)
        {
            int mid = (low + high) / 2;
            if(isPossible(mid, h, piles))
            {
                // cout << mid << endl;
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