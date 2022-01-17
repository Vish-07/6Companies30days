// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long helper(int n, int x, int c)
    {
        long long val = pow(c, x);
        if(val < n)
        {
            return helper(n, x, c + 1) + helper(n - val, x, c + 1);
        }
        else if(val == n)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int numOfWays(int n, int x)
    {
        int maxLimit = pow(n, 1.0/x) + 1;
        
        vector<vector<long long>> dp(n + 1, vector<long long>(maxLimit, -1));
        
        return helper(n, x, 1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends