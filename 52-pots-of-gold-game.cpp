//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxCoins(vector<int>&A,int n)
    {
	    int len = A.size();
	    vector<vector<int>> dp(len, vector<int>(len));
	    
	    for(int gap = 0; gap < len; ++gap)
	    {
	        for(int i = 0, j = gap; j < len; ++i, ++j)
	        {
	            if(gap == 0)
	                dp[i][j] = A[i];
	            else if(gap == 1)
	            {
	                dp[i][j] = max(A[i], A[j]);
	            }
	            else
	            {
	                int val1 = A[i] + min(dp[i + 2][j], dp[i + 1][j - 1]);
	                int val2 = A[j] + min(dp[i + 1][j - 1], dp[i][j - 2]);
	                dp[i][j] = max(val1, val2);
	            }
	        }
	    }
	    
	    return dp[0][len - 1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends