#include <iostream>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int  left = 0, sum = 0;
        int n = nums.size();
        int ans = n + 1;
        
        for(int i = 0; i < n; ++i)
        {
            sum += nums[i];
            if(sum >= target)
            {
                while(sum >= target)
                {
                    sum -= nums[left];
                    left++;
                }
                ans = min(ans, (i - left + 2));
                
            }
        }
        return (ans == (n + 1)) ? 0 : ans;
    }
};

int main()
{

        int  n, target;
        Solution ob;
        cin >> n >> target;
        vector<int> arr(n);       
        for(int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        cout << ob.minSubArrayLen(target, arr);
                
}