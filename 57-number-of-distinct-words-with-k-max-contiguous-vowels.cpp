
#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++


class Solution
{
  public:
    long long MOD = 1000000007;
    long long dp[1001][1001];
    long long helper(int n, int k, int K)
    {
        if(n == 0)
            return 1;
            
        if(dp[n][k] != -1)
            return dp[n][k];
        
        long long ans = (21 * helper(n - 1, K, K)) % MOD;
        
        if(k > 0)
        {
            long long part = (5 * helper(n - 1, k - 1, K)) % MOD;
            ans = (ans + part) % MOD;
        }
 
        dp[n][k] = ans;
        return ans;
    
    }
    int kvowelwords(int N, int K) 
    {
        memset(dp,-1,sizeof dp);
        return helper(N, K, K);
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends