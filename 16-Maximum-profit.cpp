#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) 
    {
        // Case1: n<=1 or k==0
        if(k == 0  || n <= 1)
            return 0;
            
        // Case2: 2k >= n
        if((2 * k) > n)
        {
            int ans = 0;
            for(int i = 1; i < n; ++i)
            {
                if(prices[i] > prices[i - 1])
                {
                    ans += (prices[i] - prices[i - 1]);
                }
            }
            return ans;
        }
        
        // Case3: 1 <= k < n;
        
        int dp[2 * k + 1];
        dp[0] = -prices[0];
        for(int i = 1; i <= (2 * k); ++i)
        {
            if(i % 2 == 0)
                dp[i] = INT_MIN;
            else
                dp[i] = 0;
        }
        
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j <= (2 * k); ++j)
            {
                if(j == 0)
                    dp[j] = max(dp[j], -prices[i]);
                else if(j % 2 == 0)
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                else
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
            }
        }
        return dp[2 * k - 1];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
} 