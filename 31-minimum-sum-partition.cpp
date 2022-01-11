#include <bits/stdc++.h>
using namespace std;

class Solution{

	public:
	int minDiffDp(int a[],int n,int sum,int **dp)
	{
	    int i,j;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=sum;j++)
	        {
	            int ans;
	            if(a[i-1]>j)
	            {
	                ans=dp[i-1][j];
	            }
	            else
	            {
	                ans=dp[i-1][j] || dp[i-1][j-a[i-1]];
	            }
	            dp[i][j]=ans;
	        }
	    }
	    int diff=sum;
	    for(j=sum/2;j>=0;j--)
	    {
	        if(dp[n][j]==1)
	        {
	            if(sum-2*j<diff)
	            {
	                diff=sum-2*j;
	            }
	            break;
	        }
	    }
	    return diff;
	}
	int minDiffernce(int arr[], int n) 
	{ 
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum=sum+arr[i];
	    }
	    int **memo;
	    memo=new int*[n+1];
	    for(int i=0;i<=n;i++)
	    {
	        memo[i]=new int[sum+1];
	    }
	    for(int i=0;i<=n;i++)
	    {
	        memo[i][0]=1;
	    }
	    for(int i=1;i<=sum;i++)
	    {
	        memo[0][i]=0;
	    }
	    int ans=minDiffDp(arr,n,sum,memo);
	    return ans;
	   
	} 
	
};

int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDiffernce(a, n) << "\n";
	     
    }
    return 0;
}  