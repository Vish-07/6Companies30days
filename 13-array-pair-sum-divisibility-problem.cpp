#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canPair(vector<int> nums, int k) 
    {
        int hash[k] = {0};
        int n = nums.size();
        
        for(int i = 0; i < n; ++i)
        {
            hash[nums[i] % k]++;
        }
        
        if((hash[0] % 2) == 1)
            return false;
            
        if(k % 2 == 0)
        {
            if((hash[k / 2] % 2) == 1)
                return false;
        }
        
        for(int i = 1; i <= (k / 2); ++i)
        {
            if(hash[i] != hash[k - i])
                return false;
        }
        
        return true;
        
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
} 