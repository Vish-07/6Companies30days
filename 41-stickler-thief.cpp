#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        if(n == 1)
            return arr[0];
        if(n == 2)
            return max(arr[0], arr[1]);
            
        int include = arr[0];
        int exclude = 0;
        
        for(int i = 1; i < n; ++i)
        {
            int excludeCurr = (include > exclude) ? include : exclude;
            include = exclude + arr[i];
            exclude = excludeCurr;
        }
        
        return (include > exclude) ? include : exclude;
        
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends