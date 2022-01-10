// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void getParenthesis(vector<vector<int>>& bracket, int i, int j, int n, char& name, string& ans)
    {
        if(i > j || i >= n || j >= n)
            return;
            
        if(i == j)
        {
            ans += name;
            name++;
            return;
        }
        
        ans += "(";
        getParenthesis(bracket, i, bracket[i][j], n, name, ans);
        getParenthesis(bracket, bracket[i][j] + 1, j, n, name, ans);
        ans += ")";
    }
    
    string matrixChainOrder(int p[], int n){
        vector<vector<int>> dp(n, vector<int>(n));
        vector<vector<int>> bracket(n, vector<int>(n));
        string ans = "";
        char name = 'A';
        
        for(int i = 0; i < n; ++i)
            dp[i][i] = 0;
            
        for(int gap = 2; gap < n; ++gap)
        {
            for(int i = 0; i <= (n - gap); ++i)
            {
                int j = i + gap - 1;
                dp[i][j] = INT_MAX;
                
                for(int k = i; k < j; ++k)
                {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    if(cost < dp[i][j])
                    {
                        dp[i][j] = cost;
                        bracket[i][j] = k;
                    }
                }
            }
        }
        getParenthesis(bracket, 1, n - 1, n, name, ans);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends