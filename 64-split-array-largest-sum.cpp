class Solution {
public:
    bool isPossible(vector<int>& nums, int mid, int m)
    {
        int subarr = 1;
        int sum = 0;
        for(auto x : nums)
        {
            sum += x;
            
            if(sum > mid)
            {
                subarr++;
                sum = x;
            }
        }
        return (subarr <= m);
    }
    
    int splitArray(vector<int>& nums, int m) 
    {
        int max = 0, sum = 0, ans = 0;
        for(auto x : nums)
        {
            sum += x;
            if(x > max)
                max = x;
        }
        
        if(m == nums.size())
            return max;
        
        int lo = max, hi = sum;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            
            if(isPossible(nums, mid, m))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        return ans;
    }
};